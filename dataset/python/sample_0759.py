import random
import statistics

def permute(data, k):
    if k == 0:
        return [[]]
    result = []
    for i in range(len(data)):
        remaining = data[:i] + data[i + 1:]
        for p in permute(remaining, k - 1):
            result.append([data[i]] + p)
    return result

def calculate_p_values(data1, data2, num_permutations):
    real_diff = abs(statistics.mean(data1) - statistics.mean(data2))
    count = 0
    combined = data1 + data2
    for _ in range(num_permutations):
        permuted = random.sample(combined, len(combined))
        diff = abs(statistics.mean(permuted[:len(data1)]) - statistics.mean(permuted[len(data1):]))
        if diff >= real_diff:
            count += 1
    return count / num_permutations

def main():
    data1 = [2, 4, 4, 4, 5, 5, 7, 9]
    data2 = [1, 1, 3, 3, 5, 5, 7, 9]
    num_permutations = 1000
    p_value = calculate_p_values(data1, data2, num_permutations)
    print(f'P-value: {p_value}')
main()