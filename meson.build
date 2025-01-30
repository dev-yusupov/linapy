project(
    'LinaPy', 
    'cpp', 'python', 
    version: '0.1.0', 
    default_options: [
        'buildtype=debugoptimized',
        'cpp_std=c++17'
    ])

pybind11 = dependency('pybind11')

sources = [
    'linapy/core/operations.cpp',
]

python = import('python').find_installation('python3')

python.extension_module('core', sources, dependencies: pybind11, install: true)