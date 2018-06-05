LEFT = 0
UP = 1
RIGHT = 2
DOWN = 3


def parse_to_matrix(input_file):
    matrix = input_file.read().split('\n')[:4]
    for i in range(len(matrix)):
        matrix[i] = list(map(int, matrix[i].split(' ')))
    return matrix


def print_matrix(matrix):
    pass


def transpose(matrix):
    for r in range(0,len(matrix)-1):
        for c in range(r+1,len(matrix)):
            temp = matrix[r][c]
            matrix[r][c] = matrix[c][r]
            matrix[c][r] = temp


def move_and_merge(vector, dir):
    if dir == RIGHT:
        vector.reverse()
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
    if dir == RIGHT:
        vector.reverse()


def make_turn(input_matrix, direction):
    pass


if __name__ == '__main__':
    file = open('Samples/In/1.in', 'r')
    matrix = parse_to_matrix(file)
    print(matrix)
    transpose(matrix)
    print(matrix)
    vector = [4,4,0,2]
    move_and_merge(vector, LEFT)
    print(vector)