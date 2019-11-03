from distutils.core import setup, Extension

setup(
    name="pymutable",
    version="0.0.1",
    ext_modules=[
        Extension("pymutable", ["pymutable.c"])
    ]
)
