import random
import math

def generate_data(size):
    data = []
    for _ in range(size):
        data.append(random.gauss(0, 1))
    return data

def calculate_p_value(data1, data2):
    mean1 = sum(data1) / len(data1)
    mean2 = sum(data2) / len(data2)
    variance1 = sum(((x - mean1) ** 2 for x in data1)) / len(data1)
    variance2 = sum(((x - mean2) ** 2 for x in data2)) / len(data2)
    pooled_variance = ((len(data1) - 1) * variance1 + (len(data2) - 1) * variance2) / (len(data1) + len(data2) - 2)
    t_statistic = (mean1 - mean2) / math.sqrt(pooled_variance * (1 / len(data1) + 1 / len(data2)))
    df = len(data1) + len(data2) - 2
    p_value = 2 * (1 - math.tanh(t_statistic * math.sqrt(df / (df + t_statistic ** 2))))
    return p_value

def simulate_p_values(num_simulations, sample_size):
    p_values = []
    for _ in range(num_simulations):
        data1 = generate_data(sample_size)
        data2 = generate_data(sample_size)
        p_values.append(calculate_p_value(data1, data2))
    return p_values

def main():
    num_simulations = 1000
    sample_size = 30
    p_values = simulate_p_values(num_simulations, sample_size)
    sorted_p_values = sorted(p_values)
    median_p_value = sorted_p_values[len(p_values) // 2]
    print(f'Median P-value: {median_p_value}')
main()