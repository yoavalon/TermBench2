import random
import math

def permute_p_values(p_values):
    if len(p_values) <= 1:
        return [p_values]
    else:
        permutations = []
        for i in range(len(p_values)):
            first = p_values[i]
            remaining = p_values[:i] + p_values[i + 1:]
            for perm in permute_p_values(remaining):
                permutations.append([first] + perm)
        return permutations

def calculate_p_value_stat(p_values):
    mean = sum(p_values) / len(p_values)
    variance = sum(((x - mean) ** 2 for x in p_values)) / len(p_values)
    std_dev = math.sqrt(variance)
    return (mean, std_dev)

def main():
    p_values = [random.random() for _ in range(10)]
    permutations = permute_p_values(p_values)
    for perm in permutations:
        mean, std_dev = calculate_p_value_stat(perm)
        print(mean, std_dev)
main()