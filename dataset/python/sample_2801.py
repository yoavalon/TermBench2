import random

def generate_data(size):
    data = [random.gauss(0, 1) for _ in range(size)]
    return data

def calculate_pvalue(sample1, sample2):
    combined = sample1 + sample2
    mean_diff = sum(sample1) / len(sample1) - sum(sample2) / len(sample2)
    perm_mean_diffs = []
    for _ in range(10000):
        random.shuffle(combined)
        perm_mean_diffs.append(sum(combined[:len(sample1)]) / len(sample1) - sum(combined[len(sample1):]) / len(sample2))
    return sum((1 for x in perm_mean_diffs if x >= mean_diff)) / 10000

def main():
    while True:
        data1 = generate_data(50)
        data2 = generate_data(50)
        pvalue = calculate_pvalue(data1, data2)
        print(pvalue)
main()