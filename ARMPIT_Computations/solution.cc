#include <iostream>
#include <cstdint>
#include <cassert>
#include <functional>
#include <queue>

using namespace std;

namespace {
    constexpr uint32_t trunc(uint32_t v) {
        return v & ((1 << 12) - 1);
    }

    constexpr uint32_t ORWITH(uint32_t reg, uint32_t v) {
        assert(v < (1 << 4));
        assert(reg < (1 << 12));
        return trunc(reg | v);
    }

    constexpr uint32_t LSL(uint32_t reg, uint32_t amt) {
        assert(amt < (1 << 3));
        assert(reg < (1 << 12));
        return trunc(reg << amt);
    }

    constexpr uint32_t ROR(uint32_t reg, uint32_t amt) {
        assert(amt < (1 << 3));
        assert(reg < (1 << 12));
        return trunc((reg << (12 - amt)) | (reg >> amt));
    }

    constexpr uint32_t ADDONE(uint32_t reg) {
        assert(reg < (1 << 12));
        return trunc(reg + 1);
    }

    constexpr uint32_t NOT(uint32_t reg) {
        assert(reg < (1 << 12));
        return trunc(~reg);
    }

    constexpr uint32_t ADDSHIFT(uint32_t reg, uint32_t amt) {
        assert(amt < (1 << 3));
        assert(reg < (1 << 12));
        return trunc(reg + LSL(reg, amt));
    }

    vector<function<uint32_t(uint32_t)>> get_all_ops() {
        vector<function<uint32_t(uint32_t)>> res;

        for (uint32_t v = 0; v < (1 << 4); v++) {
            res.push_back([v](uint32_t reg){
                return ORWITH(reg, v);
            });
        }

        for (uint32_t amt = 0; amt < (1 << 3); amt++) {
            if (amt != 0) {
                res.push_back([amt](uint32_t reg) {
                    return LSL(reg, amt);
                });
                res.push_back([amt](uint32_t reg) {
                    return ROR(reg, amt);
                });
            }
            res.push_back([amt](uint32_t reg) {
                return ADDSHIFT(reg, amt);
            });
        }

        res.push_back([](uint32_t reg) {
            return ADDONE(reg);
        });
        res.push_back([](uint32_t reg) {
            return NOT(reg);
        });

        return res;
    }

    void bfs(vector<int64_t>& dists, const vector<function<uint32_t(uint32_t)>>& ops) {
        queue<uint32_t> q;
        dists[0] = 0; // Distance to reg = 0 is 0.
        q.push(0);

        while (!q.empty()) {
            int64_t r64 = q.front();
            assert(r64 >= 0);
            q.pop();
            uint32_t r = static_cast<uint32_t>(r64);

            for (const auto& op : ops) {
                uint32_t r_next = op(r);
                assert(r_next < (1 << 12));
                
                if (dists[r_next] == -1) {
                    assert(dists[r] >= 0);
                    dists[r_next] = dists[r] + 1;
                    q.push(r_next);
                }
            }
        }
    }
}

int main() {
    const vector<function<uint32_t(uint32_t)>> ops = get_all_ops();

    vector<int64_t> dists(4096, -1);
    bfs(dists, ops);

    unsigned T;
    cin >> T;

    for (unsigned t = 0; t < T; t++) {
        uint32_t target;
        cin >> target;
        cout << dists[target] << endl;
    }
}
