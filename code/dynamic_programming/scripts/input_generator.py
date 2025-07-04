import random
import string
import os

def generar_input(k=100, min_len=50, max_len=100, filename="dynamic_programming_input/input.txt"):
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    with open(filename, "w") as f:
        f.write(f"{k}\n")
        for _ in range(k):
            n = random.randint(min_len, max_len)
            m = random.randint(min_len, max_len)
            s = ''.join(random.choices(string.ascii_uppercase, k=n))
            t = ''.join(random.choices(string.ascii_uppercase, k=m))
            f.write(f"{n} {s}\n")
            f.write(f"{m} {t}\n")

if __name__ == "__main__":
    generar_input()
