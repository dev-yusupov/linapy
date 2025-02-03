from linapy.lina_types import Array

class Matrix(Array):
    """
    A class to represent a matrix.

    Attributes
    ----------
    rows : int
        The number of rows in the matrix.
    columns : int
        The number of columns in the matrix.

    """

    def __init__(self, data, dtype=int):
        """
        Initialize the matrix.

        Parameters
        ----------
        data : list of lists
            The data to be stored in the matrix.
        dtype : type
            The data type of the elements in the matrix.

        """
        self.rows = len(data)
        self.columns = len(data[0]) if data else 0
        self.data = [Array(row) for row in data]
        self.dtype = dtype

    def __repr__(self):
        """
        Return the string representation of the matrix.

        Returns
        -------
        str
            The string representation of the matrix.

        """
        return f"Matrix({self.data}, rows={self.rows}, columns={self.columns})"

    def __getitem__(self, key):
        """
        Get an element from the matrix.

        Parameters
        ----------
        key : tuple
            The key to access the element in the matrix.

        Returns
        -------
        int
            The element in the matrix.

        """
        row, column = key
        return self.data[row][column]

    def __setitem__(self, key, value):
        """
        Set an element in the matrix.

        Parameters
        ----------
        key : tuple
            The key to access the element in the matrix.
        value : int
            The value to set in the matrix.

        """
        row, column = key
        self.data[row][column] = value

    def transpose(self):
        """
        Transpose the matrix.

        Returns
        -------
        Matrix
            The transposed matrix.

        """
        transposed_data = [[self.data[row][col] for row in range(self.rows)] for col in range(self.columns)]
        return Matrix(transposed_data, dtype=self.dtype)