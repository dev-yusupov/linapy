project(
    'LinaPy', 
    'cpp', 
    version: '0.1.0', 
    default_options: [
        'buildtype=debugoptimized',
        'cpp_std=c++17'
    ]
)

pybind11 = dependency('pybind11', required: true)
python = import('python').find_installation()

sources = [
    'linapy/lina_types/Array.hpp',
    'linapy/lina_types/Matrix.hpp',
    'linapy/lina_types/Vector.cpp',
    'linapy/bindings.cpp',
]

lina_types = shared_module(
    'lina_types',
    sources,
    dependencies: [pybind11, python.dependency()],
    install: true
)

# Install compiled C++ extension in Python's site-packages
install_dir = python.get_install_dir()
install_subdir('linapy', install_dir: install_dir)
install_headers('linapy/lina_types/Array.hpp', subdir: 'linapy/lina_types')
install_headers('linapy/lina_types/Matrix.hpp', subdir: 'linapy/lina_types')
install_headers('linapy/lina_types/Vector.hpp', subdir: 'linapy/lina_types')
