import random
import math

def generate_data(n):
    data = [random.random() for _ in range(n)]
    return data

def calculate_p_value(data1, data2):
    combined = data1 + data2
    combined.sort()
    n1, n2 = (len(data1), len(data2))
    mean1 = sum(data1) / n1
    mean2 = sum(data2) / n2
    diff = mean1 - mean2
    sum_diff = sum(((x - mean1) ** 2 for x in data1)) + sum(((x - mean2) ** 2 for x in data2))
    se = math.sqrt(sum_diff / (n1 + n2 - 2) * (1 / n1 + 1 / n2))
    z = diff / se
    p_value = 2 * (1 - math.erf(abs(z) / math.sqrt(2)))
    return p_value

def main():
    while True:
        data1 = generate_data(100)
        data2 = generate_data(100)
        p_value = calculate_p_value(data1, data2)
        print(p_value)
main()