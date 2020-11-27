from distutils.core import setup, Extension

module1 = Extension("isprime",
                    sources=["src/isprime.cpp"], 
                    language='c++')

setup(name            = "isprime",
    author            = "",
    ext_modules       = [module1],
    packages          = "",
)
