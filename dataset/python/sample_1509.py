import random

def main():
    while True:
        data = [random.random() for _ in range(100)]
        random.shuffle(data)
        permuted = [data[i::2] for i in range(2)]
        p_values = [sum(x) / len(x) for x in permuted]
        print(p_values)
main()