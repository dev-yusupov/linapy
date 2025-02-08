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

    def __init__(self, data: List[Union[int, float, str]], dtype: Optional[Type[T]] = None) -> None:
        """
        Initialize the vector.

        Parameters
        ----------
        data : list
            The data to be stored in the vector.
        dtype : type
            The data type of the elements in the vector.
        """
        super().__init__(data, dtype)
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
    
    def __getitem__(self, key: int) -> T:
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

        return self.data[key]
    
    def __setitem__(self, key: int, value: T) -> None:
        """
        Set an element in the vector.

        Parameters
        ----------
        key : int
            The key to access the element in the vector.
        value : int
            The value to set the element to.

        """
        self.data[key] = value

    def __add__(self, other: "Vector") -> "Vector":
        """
        Add two vectors element-wise.

        Parameters
        ----------
        other : Vector
            The vector to add to the current vector.

        Returns
        -------
        Vector
            The sum of the two vectors.

        """

        if self.length != other.length:
            raise ValueError("Vectors must be of the same length to add them.")
        
        return Vector([self.data[i] + other.data[i] for i in range(self.length)], dtype=self.dtype)
    
    def __sub__(self, other: "Vector") -> "Vector":
        """
        Subtract two vectors element-wise.

        Parameters
        ----------
        other : Vector
            The vector to subtract from the current vector.

        Returns
        -------
        Vector
            The difference of the two vectors.

        """

        if self.length != other.length:
            raise ValueError("Vectors must be of the same length to subtract them.")
        
        return Vector([self.data[i] - other.data[i] for i in range(self.length)], dtype=self.dtype)
    
    def __mul__(self, other: Union[int, float]) -> "Vector":
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

        return Vector([self.data[i] * other for i in range(self.length)], dtype=self.dtype)
    
    def dot(self, other: "Vector") -> Union[int, float]:
        """
        Compute the dot product of two vectors.

        Parameters
        ----------
        other : Vector
            The vector to compute the dot product with.

        Returns
        -------
        int
            The dot product of the two vectors.

        """

        if self.length != other.length:
            raise ValueError("Vectors must be of the same length to compute the dot product.")
        
        return sum([self.data[i] * other.data[i] for i in range(self.length)])
    

