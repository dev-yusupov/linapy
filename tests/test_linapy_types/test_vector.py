from linapy.lina_types import Vector
import pytest


@pytest.fixture
def vector():
    return Vector([1, 2, 3], dtype=int)


class TestVector:
    """

    Test cases for the Vector class.

    """

    def test_vector_initialization(self, vector):
        """
        Test the initialization of a Vector object.
        """

        assert vector == Vector([1, 2, 3])
        assert vector[0] == 1
        assert vector[1] == 2
        assert vector[2] == 3
        assert vector.length == 3

    def test_vector_initializing_with_empty_list(self):
        """
        Test initializing a Vector object with an empty list.
        """
        with pytest.raises(ValueError):
            Vector([])

    def test_vector_representation(self, vector):
        """
        Test the string representation of a Vector object.
        """
        assert repr(vector) == "Vector([1, 2, 3], length=3)"

    def test_vector_get_element(self, vector):
        """
        Test getting an element from a Vector object.
        """
        assert vector[0] == 1
        assert vector[1] == 2
        assert vector[2] == 3

    def test_vector_set_element(self, vector):
        """
        Test setting an element in a Vector object.
        """
        vector[0] = 5
        assert vector[0] == 5

        vector[1] = 6
        assert vector[1] == 6
