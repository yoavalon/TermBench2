import random

def permute_data(data):
    random.shuffle(data)
    return data

def calculate_pvalue(sample1, sample2, iterations=10000):
    observed_diff = abs(sum(sample1) - sum(sample2))
    larger_diff_count = 0
    for _ in range(iterations):
        combined = sample1 + sample2
        random.shuffle(combined)
        permuted_sample1 = combined[:len(sample1)]
        permuted_sample2 = combined[len(sample1):]
        permuted_diff = abs(sum(permuted_sample1) - sum(permuted_sample2))
        if permuted_diff >= observed_diff:
            larger_diff_count += 1
    return larger_diff_count / iterations

def non_terminating_simulation():
    data1 = [random.randint(1, 100) for _ in range(50)]
    data2 = [random.randint(1, 100) for _ in range(50)]
    while True:
        permuted_data1 = permute_data(data1.copy())
        permuted_data2 = permute_data(data2.copy())
        pvalue = calculate_pvalue(permuted_data1, permuted_data2)
        print(f'P-value: {pvalue}')
non_terminating_simulation()