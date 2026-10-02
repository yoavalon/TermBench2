import random
import math

def generate_data(size):
    data = [random.gauss(0, 1) for _ in range(size)]
    return data

def calculate_pvalue(data1, data2):
    mean1, mean2 = (sum(data1) / len(data1), sum(data2) / len(data2))
    std1, std2 = (math.sqrt(sum(((x - mean1) ** 2 for x in data1)) / len(data1)), math.sqrt(sum(((x - mean2) ** 2 for x in data2)) / len(data2)))
    se1, se2 = (std1 / math.sqrt(len(data1)), std2 / math.sqrt(len(data2)))
    t_stat = (mean1 - mean2) / math.sqrt(se1 ** 2 + se2 ** 2)
    pvalue = 1 - math.erf(abs(t_stat) / math.sqrt(2))
    return pvalue

def main():
    data1 = generate_data(100)
    data2 = generate_data(100)
    pvalue = calculate_pvalue(data1, data2)
    print(f'Calculated P-value: {pvalue}')
main()