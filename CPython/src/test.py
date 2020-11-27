import re, os
import isprime

def get_primes(p):
    assert isprime.is_prime(p), f"""{p} - Fail."""
    print(f"{p} - Sucess!")

def confirmed_prime_numbers():
    PRIMES = []

    filename = "10000.txt"
    p_10000 = os.path.realpath("__file__").replace("/__file__", "")
    if os.path.split(p_10000)[1] == "CPython":
        p_10000 = os.path.join(p_10000, filename)
    elif os.path.split(p_10000)[1] == "src":
        p_10000 = os.path.join(os.path.split(p_10000)[0], filename)
    if not os.path.exists(p_10000):
        raise Exception(f"{filename} file not found.")

    def get_txt():
        with open(p_10000, "r") as primes:
            lines = primes.readlines()[4:]
            for line in lines:
                prime_in_line = line.split("\n")
                for p in range(len(prime_in_line)):
                    primes = re.split(r"(\d+)", prime_in_line[p])
                    for p_num in primes:
                        if p_num.isdigit():
                            PRIMES.append(int(p_num))

    get_txt()

    for i in PRIMES:
        get_primes(i)   

if __name__ == "__main__":
    isprime.check_primes()
#    confirmed_prime_numbers()
#    get_primes(124247)
