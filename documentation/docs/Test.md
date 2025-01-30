# Test

As the project is written in both Python and C++, we will have to write tests for both languages. We will use `pytest` for testing the Python code and `googletest` for testing the C++ code. We will also use `pybind11` to bind the C++ code to Python.

## Testing strategy

- **Unit tests**: We will write unit tests for the core features of the project. The unit tests will be written for both Python and C++ code.
- **Integration tests**: We will write integration tests for the high-level operations in Python. The integration tests will test the interaction between the high-level operations and the low-level operations.
- **Performance tests**: We will write performance tests for the low-level operations in C++. The performance tests will test the speed and efficiency of the low-level operations.
- **CI/CD pipelines**: We will set up CI/CD pipelines for the project. The pipelines will run the tests automatically on every commit to the repository.

## Test cases

| Category          | Test Case                                      | Expected Output                                      |
|-------------------|------------------------------------------------|------------------------------------------------------|
| Matrix operations | Test matrix addition                           | Correct sum of two matrices                          |
| Matrix operations | Test matrix multiplication                     | Correct product of two matrices                      |
| Matrix operations | Test matrix transpose                          | Correct transpose of a matrix                        |
| Matrix operations | Test matrix inversion                          | Correct inverse of a matrix                          |
| Matrix operations | Test matrix determinant                        | Correct determinant of a matrix                      |
| Python tests      | Test Python function binding to C++            | Correct execution and result of the bound function   |
| Python tests      | Test exception handling in Python for C++ code | Proper exception handling and error messages         |
| Python tests      | Test performance of Python bindings            | Performance within acceptable limits                 |
| C++ tests         | Test C++ function correctness                  | Correct execution and result of the function         |
| C++ tests         | Test C++ class methods                         | Correct execution and result of class methods        |
| C++ tests         | Test C++ exception handling                    | Proper exception handling and error messages         |
| C++ tests         | Test C++ performance                           | Performance within acceptable limits                 |
| Edge cases        | Test empty matrix operations                   | Proper handling of empty matrices                    |
| Edge cases        | Test large matrix operations                   | Correct handling and performance with large matrices |
| Edge cases        | Test invalid matrix operations                 | Proper error handling for invalid operations         |
| Edge cases        | Test boundary values                           | Correct handling of boundary values                  |
| Vector operations | Test vector addition                           | Correct sum of two vectors                           |
| Vector operations | Test vector dot product                        | Correct dot product of two vectors                   |
| Vector operations | Test vector cross product                      | Correct cross product of two vectors                 |
| Vector operations | Test vector normalization                      | Correct normalization of a vector                    |
