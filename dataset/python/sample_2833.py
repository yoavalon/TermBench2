import random

def permute_values(data):
    return random.sample(data, len(data))

def calculate_pvalue(sample1, sample2):
    combined = sample1 + sample2
    original_diff = sum(sample1) - sum(sample2)
    larger_diffs = 0
    for _ in range(10000):
        permuted = permute_values(combined)
        perm_sample1 = permuted[:len(sample1)]
        perm_sample2 = permuted[len(sample1):]
        perm_diff = sum(perm_sample1) - sum(perm_sample2)
        if perm_diff >= original_diff:
            larger_diffs += 1
    return larger_diffs / 10000

def main():
    sample_a = [random.randint(1, 100) for _ in range(50)]
    sample_b = [random.randint(1, 100) for _ in range(50)]
    pvalue = calculate_pvalue(sample_a, sample_b)
    print(f'P-value: {pvalue}')
    main()
main()