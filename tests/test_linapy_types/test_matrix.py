"""

Unit tests for the Matrix class.

"""

from linapy.lina_types import Matrix
import pytest

@pytest.fixture
def matrix():
    return Matrix([[1, 2], [3, 4]], dtype=int)

class TestMatrix:
    """
    Test cases for the Matrix class.
    """

    def test_matrix_initialization(self, matrix):
        """
        Test the initialization of a Matrix object.
        """

        assert matrix == Matrix([[1, 2], [3, 4]])
        assert matrix[0, 0] == 1
        assert matrix[0, 1] == 2
        assert matrix[1, 0] == 3
        assert matrix[1, 1] == 4
        assert matrix.rows == 2
        assert matrix.columns == 2

    def test_matrix_initializing_with_empty_list(self):
        """
        Test initializing a Matrix object with an empty list.
        """
        with pytest.raises(ValueError, match="Matrix data cannot be empty"):
            Matrix([])
        
    def test_matrix_representation(self, matrix):
        """
        Test the string representation of a Matrix object.
        """
        assert repr(matrix) == "Matrix([Array([1, 2]), Array([3, 4])], rows=2, columns=2)"

    def test_matrix_get_element(self, matrix):
        """
        Test getting an element from a Matrix object.
        """
        assert matrix[0, 0] == 1
        assert matrix[0, 1] == 2
        assert matrix[1, 0] == 3
        assert matrix[1, 1] == 4

    def test_matrix_set_element(self, matrix):
        """
        Test setting an element in a Matrix object.
        """
        matrix[0, 0] = 5
        assert matrix[0, 0] == 5

        matrix[0, 1] = 6
        assert matrix[0, 1] == 6

        matrix[1, 0] = 7
        assert matrix[1, 0] == 7

        matrix[1, 1] = 8
        assert matrix[1, 1] == 8

    def test_matrix_set_element_with_different_type(self, matrix):
        """
        Test setting an element in a Matrix object with a different type.
        """
        with pytest.raises(TypeError, match="Element must be of type int"):
            matrix[0, 0] = "5"
