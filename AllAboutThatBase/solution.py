symbols = '0123456789abcdefghijklmnopqrstuvwxyz0'

def value(sym):
    return symbols.index(sym)

def eval(operand, base):
    return sum([value(p) * base**i for i,p in enumerate(reversed(operand))])

def parse_operator(op):
    if op == '+':
        return lambda x,y,z : x + y == z
    elif op == '-':
        return lambda x,y,z : x - y == z
    elif op == '*':
        return lambda x,y,z : x * y == z
    elif op == '/':
        return lambda x,y,z : y * z == x

def valid_bases(expr):
    expr = expr.split(' ')
    sym1 = expr[0]
    sym2 = expr[2]
    op = parse_operator(expr[1])
    ans = expr[4]
    res = [False for _ in range(36)]
    min_base = max([symbols.index(s) for s in ''.join([sym1, sym2, ans])])
    if min_base > 1:
        min_base += 1
    for b in range(min_base, 37):
        s1 = eval(sym1, b)
        s2 = eval(sym2, b)
        a = eval(ans, b)
        res[b - 1] = op(s1, s2, a)
    bases = ''.join(str(symbols[i+1]) if v else '' for i,v in enumerate(res))
    if bases == '':
        return 'invalid'
    return bases

N = int(input())
for _ in range(N):
    expr = input()
    print(valid_bases(expr))
