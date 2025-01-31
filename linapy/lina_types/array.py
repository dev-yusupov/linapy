"""

Base class for Matrix and Vector classes.

"""

from typing import List, Type, Optional, TypeVar, Union

T = TypeVar("T")

class Array:
    def __init__(self, data: List[Union[int, float, str]], dtype: Optional[Type[T]] = None) -> None:
        self.data = data
        
        if dtype is not None:
            self.dtype = dtype
        
        else:
            self.dtype = type(data[0]) if data else None
    
    def __repr__(self) -> str:
        return f"{self.__class__.__name__}({self.data})"

    def __getitem__(self, index: int) -> T:
        try:
            return self.data[index]

        except IndexError:
            raise IndexError("Index out of range")
    
    def __setitem__(self, index: int, value: T) -> None:
        try:
            self.data[index] = value

        except IndexError:
            raise IndexError("Index out of range")
    
    def __len__(self) -> int:
        return len(self.data)
    