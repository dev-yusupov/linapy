from typing import TypeVar, List, Type, Generic, Union, Optional

from linapy.lina_types.array import Array

T = TypeVar("T")


class Vector(Array, Generic[T]):
    """
    A class to represent a vector.

    Attributes
    ----------
    length : int
        The length of the vector.

    Methods
    -------
    __getitem__(key: int) -> T
        Get an element from the vector.

    Examples

    Creating a new Vector object:

    >>> from linapy.lina_types import Vector
    >>> vector = Vector([1, 2, 3], dtype=int)

    """

    def __init__(self, data: List[T], dtype: Optional[Type[T]] = None) -> None:
        """
        Initialize the vector.

        Parameters
        ----------
        data : list
            The data to be stored in the vector.
        dtype : type
            The data type of the elements in the vector.
        """
        super().__init__(data, dtype)  # type: ignore
        self.length: int = len(data)

    def __repr__(self) -> str:
        """
        Return the string representation of the vector.

        Returns
        -------
        str
            The string representation of the vector.
        """
        return f"Vector({self.data}, length={self.length})"

    def __getitem__(self, key: int) -> T:  # type: ignore
        """
        Get an element from the vector.

        Parameters
        ----------
        key : int
            The key to access the element in the vector.

        Returns
        -------
        int
            The element in the vector.

        """

        return self.data[key]  # type: ignore

    def __setitem__(self, key: int, value: T) -> None:  # type: ignore
        """
        Set an element in the vector.

        Parameters
        ----------
        key : int
            The key to access the element in the vector.
        value : int
            The value to set the element to.

        """
        self.data[key] = value  # type: ignore

    def __add__(self, other: "Vector[T]") -> "Vector[T]":  # type: ignore
        """
        Add two vectors element-wise.

        Parameters
        ----------
        other : Array
            The array to add to the current vector.

        Returns
        -------
        Vector
            The sum of the two vectors.

        """
        if not isinstance(other, Vector) or self.length != other.length:
            raise ValueError("Vectors must be of the same length to add them.")

        return Vector(
            [self._add_elements(self.data[i], other.data[i]) for i in range(self.length)], dtype=self.dtype  # type: ignore
        )

    def __sub__(self, other: "Vector[T]") -> "Vector[T]":  # type: ignore
        """
        Subtract two vectors element-wise.

        Parameters
        ----------
        other : Array
            The array to subtract from the current vector.

        Returns
        -------
        Vector
            The difference of the two vectors.

        """
        if not isinstance(other, Vector) or self.length != other.length:
            raise ValueError("Vectors must be of the same length to subtract them.")

        return Vector(
            [self._sub_elements(self.data[i], other.data[i]) for i in range(self.length)], dtype=self.dtype  # type: ignore
        )

    def __mul__(self, other: Union[int, float]) -> "Vector[T]":
        """
        Multiply the vector by a scalar.

        Parameters
        ----------
        other : int
            The scalar to multiply the vector by.

        Returns
        -------
        Vector
            The product of the vector and the scalar.

        """
        return Vector(
            [self._mul_elements(self.data[i], other) for i in range(self.length)], dtype=self.dtype  # type: ignore
        )

    def dot(self, other: "Vector[T]") -> T:
        """
        Compute the dot product of two vectors.

        Parameters
        ----------
        other : Array
            The array to compute the dot product with.

        Returns
        -------
        int
            The dot product of the two vectors.

        """
        if not isinstance(other, Vector) or self.length != other.length:
            raise ValueError(
                "Vectors must be of the same length to compute the dot product."
            )

        return sum([self._mul_elements(self.data[i], other.data[i]) for i in range(self.length)])  # type: ignore

    def _add_elements(self, a: T, b: T) -> T:
        if isinstance(a, str) or isinstance(b, str):
            raise TypeError("Cannot add string elements in a vector.")
        return a + b  # type: ignore

    def _sub_elements(self, a: T, b: T) -> T:
        if isinstance(a, str) or isinstance(b, str):
            raise TypeError("Cannot subtract string elements in a vector.")
        return a - b  # type: ignore

    def _mul_elements(self, a: T, b: Union[int, float]) -> T:
        if isinstance(a, str):
            raise TypeError("Cannot multiply string elements in a vector.")
        return a * b  # type: ignore
