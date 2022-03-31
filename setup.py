from setuptools import Extension, setup
from Cython.Build import cythonize
import os

mpi_build_args = os.popen('mpicc -compile_info').read().strip().split()[1:]
mpi_link_args = os.popen('mpicc -link_info').read().strip().split()[1:]
print(mpi_build_args)

setup(
    name='example',
    ext_modules=cythonize([Extension(
        "example",
        ["example.pyx"],
        libraries=['example'],
        extra_compile_args = mpi_build_args,
        extra_link_args = mpi_link_args
        )]),
    zip_safe=False,
)
