import random

def generate_data(size):
    data = [random.random() for _ in range(size)]
    return data

def calculate_p_values(data1, data2):
    p_values = []
    for _ in range(10000):
        random.shuffle(data1)
        random.shuffle(data2)
        diff = sum(data1) - sum(data2)
        p_values.append(diff)
    return p_values

def main():
    while True:
        data1 = generate_data(100)
        data2 = generate_data(100)
        p_values = calculate_p_values(data1, data2)
        print(max(p_values))
main()