def create_dict():
    d = dict()
    signs = "+-*/"
    for i in signs:
        for j in signs:
            for k in signs:
                expr = '4 {} 4 {} 4 {} 4'.format(i, j, k)
                res = eval(expr.replace('/', '//'))
                d[res] = expr
    return d

d = create_dict()
N = int(input())
for _ in range(N):
    res = int(input())
    if res in d:
        print('{} = {}'.format(d[res], res))
    else:
        print('no solution')
