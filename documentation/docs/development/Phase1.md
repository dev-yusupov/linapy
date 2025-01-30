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

## Operations

All operations will be written in C++ to achieve better performance. We will use `pybind11` to bind the C++ code to Python. Then in Python we will use the C++ code to perform the operations.

### Vector operations

- Addition (Vector + Vector) => Vector. Adding two vectors will return a new vector.
- Subtraction (Vector - Vector) => Vector. Subtracting two vectors will return a new vector.
- Scalar multiplication (Vector * scalar) => Vector. Multiplying a vector by a scalar will return a new vector.
- Dot product (Vector @ Vector) => scalar. Multiplying two vectors will return a scalar.
- Norm (Vector.norm()) => scalar. The norm of a vector is the length of the vector.
- Projection (projection(Vector, Vector)) => Vector. The projection of a vector onto another vector.
- Cross product (Vector.cross(Vector)) => Vector. The cross product of two vectors.
- Angle between two vectors (Vector.angle(Vector)) => scalar. The angle between two vectors.
- Vector length (Vector.length()) => scalar. The length of the vector.
- Vector direction (Vector.direction()) => Vector. The direction of the vector.
- Vector equality (Vector == Vector) => bool. Check if two vectors are equal.
- Vector inequality (Vector != Vector) => bool. Check if two vectors are not equal.
- Vector less than (Vector < Vector) => bool. Check if a vector is less than another vector.
- Vector greater than (Vector > Vector) => bool. Check if a vector is greater than another vector.
- Vector less than or equal (Vector <= Vector) => bool. Check if a vector is less than or equal to another vector.
- Vector greater than or equal (Vector >= Vector) => bool. Check if a vector is greater than or equal to another vector.
- Vector indexing (Vector[0]) => scalar. Get the value at the index.
- Vector slicing (Vector[0:2]) => Vector. Get a slice of the vector.
- Vector length (Vector.length()) => scalar. Get the length of the vector.

### Matrix operations

- Addition (Matrix + Matrix) => Matrix. Adding two matrices will return a new matrix.
- Subtraction (Matrix - Matrix) => Matrix. Subtracting two matrices will return a new matrix.
- Scalar multiplication (Matrix * scalar) => Matrix. Multiplying a matrix by a scalar will return a new matrix.
- Matrix multiplication (Matrix @ Matrix) => Matrix. Multiplying two matrices will return a new matrix.
- Transpose (transpose(Matrix)) => Matrix. Transposing a matrix will return a new matrix.
- Trace (trace(Matrix)) => scalar. The trace of a matrix is the sum of the diagonal elements.
- Determinant (determinant(Matrix)) => scalar. The determinant of a matrix.
- Inverse (inverse(Matrix)) => Matrix. The inverse of a matrix.
- Rank (rank(Matrix)) => scalar. The rank of a matrix.
- Matrix equality (Matrix == Matrix) => bool. Check if two matrices are equal.
- Matrix inequality (Matrix != Matrix) => bool. Check if two matrices are not equal.
- Matrix less than (Matrix < Matrix) => bool. Check if a matrix is less than another matrix.
- Matrix greater than (Matrix > Matrix) => bool. Check if a matrix is greater than another matrix.
- Matrix less than or equal (Matrix <= Matrix) => bool. Check if a matrix is less than or equal to another matrix.
- Matrix greater than or equal (Matrix >= Matrix) => bool. Check if a matrix is greater than or equal to another matrix.
- Matrix indexing (Matrix[0]) => Vector. Get the row at the index.
- Matrix slicing (Matrix[0:2]) => Matrix. Get a slice of the matrix.
- Matrix row (Matrix.row(0)) => Vector. Get the row of the matrix.
- Matrix column (Matrix.column(0)) => Vector. Get the column of the matrix.
- Matrix shape (Matrix.shape()) => tuple. Get the shape of the matrix.
- Matrix size (Matrix.size()) => scalar. Get the size of the matrix.
- Matrix flatten (Matrix.flatten()) => Vector. Flatten the matrix.
- Matrix reshape (Matrix.reshape((2, 3))) => Matrix. Reshape the matrix.
- Matrix stack (Matrix.stack(Matrix)) => Matrix. Stack two matrices.
- Matrix split (Matrix.split(2)) => List[Matrix]. Split the matrix into two matrices.
- Matrix concatenate (Matrix.concatenate(Matrix)) => Matrix. Concatenate two matrices.
- Matrix diagonal (Matrix.diagonal()) => Vector. Get the diagonal of the matrix.
- Matrix diagonalize (diagonalize(Matrix)) => Matrix. Diagonalize the matrix.
- Matrix eigenvalues (eigenvalues(Matrix)) => Vector. Get the eigenvalues of the matrix.
- Matrix eigenvectors (eigenvectors(Matrix)) => Matrix. Get the eigenvectors of the matrix.
- Matrix LU decomposition (lu_decompose(Matrix)) => Matrix. LU decomposition of the matrix.
- Matrix QR decomposition (qr_decompose(Matrix)) => Matrix. QR decomposition of the matrix.
- Matrix Cholesky decomposition (cholesky_decompose(Matrix)) => Matrix. Cholesky decomposition of the matrix.
- Matrix SVD decomposition (svd_decompose(Matrix)) => Matrix. SVD decomposition of the matrix.
- Matrix solve (solve(Matrix, Vector)) => Vector. Solve a linear system of equations.
- Matrix least squares (least_squares(Matrix, Vector)) => Vector. Solve a least squares problem.
- Matrix norm (Matrix.norm()) => scalar. The norm of the matrix.
- Matrix frobenius norm (Matrix.frobenius_norm()) => scalar. The Frobenius norm of the matrix.
- Matrix infinity norm (Matrix.infinity_norm()) => scalar. The infinity norm of the matrix.
- Matrix L1 norm (Matrix.l1_norm()) => scalar. The L1 norm of the matrix.
- Matrix L2 norm (Matrix.l2_norm()) => scalar. The L2 norm of the matrix.
- Matrix projection (projection(Matrix, Matrix)) => Matrix. The projection of a matrix onto another matrix.
