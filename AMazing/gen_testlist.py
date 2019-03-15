import os

file_extension = '.png'
test_folder = 'test/'

if __name__ == '__main__':
    tests = [f[:-len(file_extension)] for f
             in os.listdir(test_folder) 
             if f.endswith(file_extension)]
    tests.sort()
    with open('testlist', 'w') as f:
        for t in tests:
            f.write(t + '\n')
