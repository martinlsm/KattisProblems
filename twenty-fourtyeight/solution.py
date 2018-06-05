import sys


LEFT = 0
UP = 1
RIGHT = 2
DOWN = 3


def parse_to_matrix():
    matrix = []
    for i in range(4):
        matrix.append(list(map(int, sys.stdin.readline()[:-1].split(' '))))
    dir = int(sys.stdin.readline())
    return matrix, dir


def print_matrix(matrix):
    for row in matrix:
        print('{} {} {} {}'.format(*row))


def transpose(matrix):
    for r in range(0,len(matrix)-1):
        for c in range(r+1,len(matrix)):
            temp = matrix[r][c]
            matrix[r][c] = matrix[c][r]
            matrix[c][r] = temp


def move_and_merge(vector, dir):
    if dir == RIGHT:
        vector.reverse()
    #remove zero padding
    for i in range(len(vector)):
        move_count = 0
        for k in range(i):
            if vector[k] != 0:
                move_count = 0
            else:
                move_count += 1
        if move_count != 0:
            vector[i - move_count] = vector[i]
            vector[i] = 0
    #merge duplicates
    for i in range(len(vector)-1):
        if vector[i] == vector[i+1]:
            vector[i] *= -2
            vector[i+1] = 0
            for k in range(i+1,len(vector)-1):
                vector[k] = vector[k+1]
            vector[-1] = 0
    #remove negative signs
    for i in range(len(vector)):
        vector[i] = abs(vector[i])
    if dir == RIGHT:
        vector.reverse()


def make_turn(input_matrix, direction):
    if direction == LEFT:
        for row in input_matrix:
            row = move_and_merge(row, LEFT)
    if direction == UP:
        transpose(input_matrix)
        for row in input_matrix:
            row = move_and_merge(row, LEFT)
        transpose(input_matrix)
    if direction == RIGHT:
        for row in input_matrix:
            row = move_and_merge(row, RIGHT)
    if direction == DOWN:
        transpose(input_matrix)
        for row in input_matrix:
            row = move_and_merge(row, RIGHT)
        transpose(input_matrix)
    #return input_matrix


if __name__ == '__main__':
    matrix, dir = parse_to_matrix()
    make_turn(matrix, dir)
    print_matrix(matrix)
