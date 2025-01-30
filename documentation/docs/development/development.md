# Phase 1

## Things to consider

- In C++ we have to consider using namespaces to organize the code `namespace my_namespace { ... }`
- In Python we have to consider using modules to organize the code `import linapy.matrix`
- Error handling in both C++ and Python code
- Using `pytest` for testing the Python code
- Using `googletest` for testing the C++ code
- Using `pybind11` to bind the C++ code to Python
- Setting up CI/CD pipelines for the project

## Types

- Matrix
- Vector
- SparseMatrix

### Array

Array is the base class for all the types. It will contain the common operations that are shared by all the types. In Python and C++ we will have to implement the Array class in separate to achieve a better performance. Also templates in C++ will be used as it will allow us to write generic code for multiple types.

Parameters:

- `data`: The data of the array
- `dtype`: The data type of the array (e.g., int, float) and it is optional

```python
arr = Array([1, 2, 3, 4, 5], dtype=int) # Array of integers
arr1 = Array([1, 2, 3, 4, 5], dtype=float) # Array of floats => Array([1.0, 2.0, 3.0, 4.0, 5.0])
```

### Vector

Vector is the class that will contain the operations that are specific to vectors. It will inherit from the Array class.

Parameters:

- `data`: The data of the vector
- `dtype`: The data type of the vector (e.g., int, float) and it is optional

```python
Vector([1, 2, 3, 4, 5], dtype=int)
```

### Matrix

Matrix is the class that will contain the operations that are specific to matrices. It will inherit from the Array class and contains Arrays as its rows. Users just pass list of lists to create a Matrix to data parameter. Internally it will create Arrays from the lists and store them as rows.

Parameters:
rows: List of Arrays
dtype: The data type of the matrix (e.g., int, float) and it is optional. If not provided, it will be inferred from the data. In Arrays the dtype should not be provided so the `dtype` of the Matrix will be general for all the Arrays.

```python
Matrix([
    [1, 2, 3],
    [4, 5, 6],
], dtype=int)

```
