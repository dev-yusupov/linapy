"""

Unit tests for the Array class.

"""

from linapy.lina_types import Array
import pytest


@pytest.fixture
def array():
    return Array([1, 2, 3, 4], dtype=int)


class TestArray:  # Renamed from ArrayTests to TestArray
    """
    Test cases for the Array class.
    """

    def test_array_initialialization(self, array):
        """
        Test the initialization of an Array object.
        """

        assert array == Array([1, 2, 3, 4])
        assert array[0] == 1
        assert array[1] == 2
        assert array[2] == 3
        assert array[3] == 4
        assert len(array) == 4

    def test_array_initializing_with_empty_list(self):
        """
        Test initializing an Array object with an empty list.
        """
        with pytest.raises(ValueError):
            Array([])

    def test_array_representation(self, array):
        """
        Test the string representation of an Array object.
        """
        assert repr(array) == "Array([1, 2, 3, 4])"

    def test_array_get_element(self, array):
        """
        Test getting an element from an Array object.
        """
        assert array[0] == 1
        assert array[1] == 2
        assert array[2] == 3
        assert array[3] == 4

    def test_array_set_element(self, array):
        """
        Test setting an element in an Array object.
        """
        array[0] = 5
        assert array[0] == 5

    def test_array_set_element_with_different_type(self, array):
        """
        Test setting an element in an Array object with a different type.
        """
        with pytest.raises(TypeError):
            array[0] = "5"

    def test_array_length(self, array):
        """
        Test getting the length of an Array object.
        """
        assert len(array) == 4

    def test_array_iteration(self, array):
        """
        Test iterating over the elements of an Array object.
        """
        elements = [1, 2, 3, 4]
        for i, element in enumerate(array):
            assert element == elements[i]

    def test_array_addition(self):
        """
        Test adding two Array objects.
        """
        array1 = Array([1, 2, 3, 4])
        array2 = Array([5, 6, 7, 8])

        result = array1 + array2

        assert result == Array([6, 8, 10, 12])

    def test_array_addition_with_different_lengths(self):
        """
        Test adding two Array objects with different lengths.
        """
        array1 = Array([1, 2, 3, 4])
        array2 = Array([5, 6, 7])

        with pytest.raises(ValueError):
            array1 + array2

    def test_array_subtraction(self):
        """
        Test subtracting two Array objects.
        """
        array1 = Array([5, 6, 7, 8])
        array2 = Array([1, 2, 3, 4])

        result = array1 - array2

        assert result == Array([4, 4, 4, 4])

    def test_array_subtraction_with_different_lengths(self):
        """
        Test subtracting two Array objects with different lengths.
        """
        array1 = Array([1, 2, 3, 4])
        array2 = Array([5, 6, 7])

        with pytest.raises(ValueError):
            array1 - array2

    def test_array_multiplication(self):
        """
        Test multiplying an Array object by a scalar.
        """
        array = Array([1, 2, 3, 4])
        result = array * 2

        assert result == Array([2, 4, 6, 8])

    def test_array_equality(self):
        """
        Test the equality of two Array objects.
        """
        array1 = Array([1, 2, 3, 4])
        array2 = Array([1, 2, 3, 4])

        assert array1 == array2

    def test_array_inequality(self):
        """
        Test the inequality of two Array objects.
        """
        array1 = Array([1, 2, 3, 4])
        array2 = Array([5, 6, 7, 8])

        assert array1 != array2

    def test_array_dtype(self):
        """
        Test the dtype of an Array object.
        """
        array = Array([1, 2, 3, 4])
        assert array.dtype == int

        array = Array([1.0, 2.0, 3.0, 4.0])
        assert array.dtype == float

        array = Array(["1", "2", "3", "4"])
        assert array.dtype == str

    def test_array_initialize_int_with_dtype_float(self):
        """
        Test initializing an Array object with dtype float.
        """
        array = Array([1, 2, 3, 4], dtype=float)

        assert array.dtype == float
        assert array == Array([1.0, 2.0, 3.0, 4.0])
