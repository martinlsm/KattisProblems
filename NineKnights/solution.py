def can_attack(k1, k2):
    r1, c1 = k1
    r2, c2 = k2
    return abs(r2 - r1) == 2 and abs(c2 - c1) == 1 \
        or abs(r2 - r1) == 1 and abs(c2 - c1) == 2

def get_knights(board):
    knights = []
    for r in range(5):
        for c in range(5):
            if board[r][c] == 'k':
                knights.append((r,c))
    return knights

board = []
for i in range(5):
    board.append(list(input()))

knights = get_knights(board)

if len(knights) != 9:
    print('invalid')
    exit(0)

for i in range(len(knights)):
    for j in range(i + 1, len(knights)):
        k1 = knights[i]
        k2 = knights[j]
        if can_attack(k1, k2):
            print('invalid')
            exit(0)

print('valid')
