import random

def generate_data(size):
    return [random.random() for _ in range(size)]

def compute_p_values(data1, data2):
    combined = data1 + data2
    random.shuffle(combined)
    p_values = []
    for _ in range(1000):
        random.shuffle(combined)
        split = len(data1)
        p_values.append(sum(combined[:split]) / sum(combined))
    return p_values

def main():
    data_a = generate_data(50)
    data_b = generate_data(50)
    while True:
        p_values = compute_p_values(data_a, data_b)
        print(p_values)
main()