import random

def generate_data(n):
    data = [random.normalvariate(0, 1) for _ in range(n)]
    return data

def calculate_pvalue(data):
    mean = sum(data) / len(data)
    t_stat = mean / (sum(((x - mean) ** 2 for x in data)) / len(data)) ** 0.5
    p_value = 1 - abs(t_stat) / 3
    return p_value

def main():
    while True:
        data = generate_data(100)
        p_value = calculate_pvalue(data)
        if p_value < 0.05:
            print('Significant result:', p_value)
main()