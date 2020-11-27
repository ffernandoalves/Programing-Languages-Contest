Version using [Python/C API](https://docs.python.org/3/c-api/index.html) aka CPython.

## INSTALL

Using virtualenv:

```
cd CPython
virtualenv -p /usr/bin/python3.7 venv 
source venv/bin/activate
venv/bin/python3.7 setup.py install
```

## TO USE

```venv/bin/python3.7 src/test.py```

## Comments

The `confirmed_prime_numbers()` function tests `is_prime()` in [`isprime.cpp`](https://github.com/ffernandoalves/Programing-Languages-Contest/blob/master/CPython/src/isprime.cpp) using the prime numbers from the `10000.txt` files, 
taken from [link](https://primes.utm.edu/lists/small/10000.txt).
