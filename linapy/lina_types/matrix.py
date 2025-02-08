from typing import List, Tuple, Type, TypeVar, Generic, Optional

from linapy.lina_types import Array

T = TypeVar("T")


class Matrix(Array, Generic[T]):
    """
    A class to represent a matrix.

    Attributes
    ----------
    rows : int
        The number of rows in the matrix.
    columns : int
        The number of columns in the matrix.

    Methods
    -------
    __getitem__(key: Tuple[int, int]) -> T
        Get an element from the matrix.
    __setitem__(key: Tuple[int, int], value: T) -> None
        Set an element in the matrix.
    transpose() -> 'Matrix[T]'

    Examples
    --------
    Creating a new Matrix object:

    >>> from linapy.lina_types import Matrix
    >>> matrix = Matrix([[1, 2], [3, 4]], dtype=int)

    """

    def __init__(self, data: List[List[T]], dtype: Optional[Type[T]] = None) -> None:
        """
        Initialize the matrix.

        Parameters
        ----------
        data : list of lists
            The data to be stored in the matrix.
        dtype : type
            The data type of the elements in the matrix.

        """
        if not data or not any(data):
            raise ValueError("Matrix data cannot be empty")
        self.rows: int = len(data)
        self.columns: int = len(data[0]) if data else 0
        self.data: List[Array] = [Array(row) for row in data]  # type: ignore
        self.dtype: Optional[Type[T]] = dtype  # type: ignore

    def __repr__(self) -> str:
        """
        Return the string representation of the matrix.

        Returns
        -------
        str
            The string representation of the matrix.

        """
        return f"Matrix({self.data}, rows={self.rows}, columns={self.columns})"

    def __getitem__(self, key: Tuple[int, int]) -> T:  # type: ignore
        """
        Get an element from the matrix.

        Parameters
        ----------
        key : tuple
            The key to access the element in the matrix.

        Returns
        -------
        T
            The element in the matrix.

        """
        row, column = key
        return self.data[row][column]  # type: ignore

    def __setitem__(self, key: Tuple[int, int], value: T) -> None:  # type: ignore
        """
        Set an element in the matrix.

        Parameters
        ----------
        key : tuple
            The key to access the element in the matrix.
        value : T
            The value to set in the matrix.

        """
        row, column = key
        if self.dtype is not None and not isinstance(value, self.dtype):
            raise TypeError(f"Element must be of type {self.dtype.__name__}")
        self.data[row][column] = value  # type: ignore

    def transpose(self) -> "Matrix[T]":
        """
        Transpose the matrix.

        Returns
        -------
        Matrix
            The transposed matrix.

        """
        transposed_data: List[List[T]] = [
            [self.data[row][col] for row in range(self.rows)]  # type: ignore
            for col in range(self.columns)
        ]
        return Matrix(transposed_data, dtype=self.dtype)
