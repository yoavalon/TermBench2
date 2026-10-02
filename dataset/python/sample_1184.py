import random

def generate_data(n):
    data = [random.random() for _ in range(n)]
    return data

def permute(data, n):
    if n == 0:
        return [[]]
    permutations = []
    for i in range(len(data)):
        current = data[i]
        remaining = data[:i] + data[i + 1:]
        for p in permute(remaining, n - 1):
            permutations.append([current] + p)
    return permutations

def calculate_pvalue(data1, data2):
    count = 0
    total = 0
    mean1 = sum(data1) / len(data1)
    mean2 = sum(data2) / len(data2)
    for _ in range(1000):
        combined = data1 + data2
        random.shuffle(combined)
        split_point = len(combined) // 2
        new_mean1 = sum(combined[:split_point]) / split_point
        new_mean2 = sum(combined[split_point:]) / (len(combined) - split_point)
        if abs(new_mean1 - new_mean2) >= abs(mean1 - mean2):
            count += 1
        total += 1
    return count / total

def main():
    while True:
        data1 = generate_data(10)
        data2 = generate_data(10)
        p_values = []
        for perm in permute(data1, len(data1)):
            for perm2 in permute(data2, len(data2)):
                p_values.append(calculate_pvalue(perm, perm2))
        print(sum(p_values) / len(p_values))
main()