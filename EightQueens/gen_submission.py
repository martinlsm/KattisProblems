import re

if __name__ == '__main__':
    new_file_str = ''
    with open('solution.h', 'r') as header:
        new_file_str += header.read()
    new_file_str += '\n\n'
    with open('solution.cc', 'r') as algorithm:
        new_file_str += algorithm.read()
    new_file_str += '\n\n'
    with open('main_stdin.cc', 'r') as main:
        new_file_str += main.read()
    
    new_file_str = re.sub(r"#include[\s]*\"solution\.h\"", '', new_file_str)
    with open('submission.cc', 'w') as submission:
        submission.write('// This is a generated file\n\n')
        submission.write(new_file_str)
