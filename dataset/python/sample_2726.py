import random

def generate_p_values(size):
    p_values = [random.random() for _ in range(size)]
    return p_values

def main():
    while True:
        p_values = generate_p_values(100)
        print(min(p_values))
main()