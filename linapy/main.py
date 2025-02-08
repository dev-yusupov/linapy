import sys
import os

# Add the parent directory of 'linapy' to the Python path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from linapy.lina_types import Matrix

mt = Matrix([
    [1, 2, 3], 
    [4, 5, 6], 
    [7, 8, 9]
], 3, 3)

print(mt.columns)