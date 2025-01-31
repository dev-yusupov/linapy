"""
Base class for Matrix and Vector classes.
"""

from typing import List, Type, Optional, TypeVar, Union, Iterator

T = TypeVar("T")

class Array:
    """
    Array is the base class for the Matrix and Vector classes.

    Parameters
    ----------
    data : List[Union[int, float, str]]
        The data to be stored in the array.
    
    dtype : Optional[Type[T]]
        The type of the data to be stored in the array. If not provided, the type of the first element in the data will be used.

    Attributes
    ----------
    data : List[Union[int, float, str]]
        The data stored in the array.

    dtype : Type[T]
        The type of the data stored in the array.

    Methods:
    --------
    __getitem__(index: int) -> T
        Returns the element at the specified index.

    __setitem__(index: int, value: T) -> None
        Sets the element at the specified index to the specified value.

    __len__() -> int
        Returns the length of the array.
    
    __repr__() -> str
        Returns a string representation of the array.

    __iter__() -> Iterator[T]
        Returns an iterator over the elements of the array.

    __eq__(other: "Array") -> bool
        Checks if two arrays are equal.

    __ne__(other: "Array") -> bool
        Checks if two arrays are not equal.

    __add__(other: "Array") -> "Array"
        Adds two arrays element-wise.

    __sub__(other: "Array") -> "Array"
        Subtracts two arrays element-wise.

    __mul__(other: Union[int, float]) -> "Array"
        Multiplies each element of the array by a scalar.

    Examples
    --------
    Creating a new Array object:

    >>> from linapy.lina_types import Array
    >>> array = Array([1, 2, 3, 4])
    >>> print(array) # Array([1, 2, 3, 4])

    Accessing elements in the array:

    >>> print(array[0]) # 1
    >>> print(array[1]) # 2
    >>> print(array[2]) # 3

    Setting elements in the array:
    
    >>> array[0] = 5
    >>> print(array) # Array([5, 2, 3, 4])

    Getting the length of the array:

    >>> print(len(array)) # 4

    Iterating over the elements of the array:

    >>> for element in array:
    ...     print(element)
    1
    2
    3
    4

    Checking if two arrays are equal:
    
    >>> array2 = Array([1, 2, 3, 4])
    >>> print(array == array2) # True

    Adding two arrays element-wise:
    
    >>> array3 = array + array2
    >>> print(array3) # Array([2, 4, 6, 8])

    Subtracting two arrays element-wise:

    >>> array4 = array3 - array
    >>> print(array4) # Array([1, 2, 3, 4])

    Multiplying each element of the array by a scalar:

    >>> array5 = array * 2
    >>> print(array5) # Array([2, 4, 6, 8])

    """

    def __init__(self, data: List[Union[int, float, str]], dtype: Optional[Type[T]] = None) -> None:
        if not data:
            raise ValueError("Data cannot be initialized as an empty list")
        
        self.data: List[Union[int, float, str]] = data
        self.dtype: Type[T] = dtype if dtype is not None else type(data[0])
    
    def __repr__(self) -> str:
        return f"{self.__class__.__name__}({self.data})"

    def __getitem__(self, index: int) -> T:
        try:
            return self.data[index]
        except IndexError:
            raise IndexError("Index out of range")
    
    def __setitem__(self, index: int, value: T) -> None:
        if not isinstance(value, self.dtype):
            raise TypeError(f"Value must be of type {self.dtype.__name__}, got {type(value).__name__} instead")
        try:
            self.data[index] = value
        except IndexError:
            raise IndexError("Index out of range")
    
    def __len__(self) -> int:
        return len(self.data)
    
    def __iter__(self) -> Iterator[T]:
        return iter(self.data)
    
    def __eq__(self, other: "Array") -> bool:
        return self.data == other.data
    
    def __ne__(self, other: "Array") -> bool:
        return self.data != other.data
    
    def __add__(self, other: "Array") -> "Array":
        if len(self) != len(other):
            raise ValueError("Arrays must be of the same length to be added")
        return self.__class__([a + b for a, b in zip(self, other)])
    
    def __sub__(self, other: "Array") -> "Array":
        if len(self) != len(other):
            raise ValueError("Arrays must be of the same length to be subtracted")
        return self.__class__([a - b for a, b in zip(self, other)])
    
    def __mul__(self, other: Union[int, float]) -> "Array":
        return self.__class__([a * other for a in self])
