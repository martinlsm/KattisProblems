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


def make_turn(input, direction):
    pass


if __name__ == '__main__':
    file = open('Samples/In/1.in', 'r')
    matrix = parse_to_matrix(file)
    print(matrix)