## Writing tests
Add a test case named _'foo'_ by adding the input to `test/foo.in` and the expected output to `test/foo.expected`.
Then `make` the project and execute `./run_test`. All test cases will be run and showing which passed and which failed.

It is also possible to try the algorithm from _stdin_ by running `./main_stdin` instead.

## Writing the algorithm
The `solve` method in `solution.cc` is what is called when executing the algorithm.
Modify this method body to you liking until all your tests pass.

## Producing a submission
I've added a small _Python-script_ called `gen_submission.py` to be run in order to submit a solution.
It is rather untested, but works by merging `solution.h`, `solution.cc` and `main_stdin.cc` into a single C++ file.
The generated file `submission.cc` is then what should be submitted to the _Kattis_ judge.
