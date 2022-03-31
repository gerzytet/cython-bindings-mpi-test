sudo mpicc -fPIC -shared cexample.c -o /usr/local/lib/libexample.so
python3 setup.py build_ext --inplace
mpiexec -n 3 python3 example_test.py
