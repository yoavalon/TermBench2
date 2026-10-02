import random

def permute(data, k, p_values):
    if k == len(data):
        p_values.append(data[:])
    else:
        for i in range(k, len(data)):
            data[k], data[i] = (data[i], data[k])
            permute(data, k + 1, p_values)
            data[k], data[i] = (data[i], data[k])

def generate_data(n):
    return [random.random() for _ in range(n)]

def main():
    data = generate_data(10)
    p_values = []
    permute(data, 0, p_values)
    main()
main()