import random
import statistics

def permute(data1, data2):
    combined = data1 + data2
    random.shuffle(combined)
    mid = len(combined) // 2
    return (combined[:mid], combined[mid:])

def calculate_pvalue(sample1, sample2, observed_diff):
    p_values = []
    for _ in range(10000):
        perm_sample1, perm_sample2 = permute(sample1, sample2)
        perm_diff = abs(statistics.mean(perm_sample1) - statistics.mean(perm_sample2))
        if perm_diff >= observed_diff:
            p_values.append(1)
        else:
            p_values.append(0)
    return sum(p_values) / 10000

def main():
    data1 = [random.random() for _ in range(50)]
    data2 = [random.random() for _ in range(50)]
    observed_diff = abs(statistics.mean(data1) - statistics.mean(data2))
    p_value = calculate_pvalue(data1, data2, observed_diff)
    print(p_value)
    main()
main()