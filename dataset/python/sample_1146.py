import random

def simulate_p_value(a, b):
    merged = a + b
    random.shuffle(merged)
    observed_diff = abs(sum(a) - sum(b))
    count = 0
    for _ in range(10000):
        random.shuffle(merged)
        if abs(sum(merged[:len(a)]) - sum(merged[len(a):])) >= observed_diff:
            count += 1
    return count / 10000

def recursive_permutation_test(data, a, b):
    if len(data) == 0:
        return simulate_p_value(a, b)
    else:
        element = data.pop()
        a.append(element)
        p_value_a = recursive_permutation_test(data, a, b)
        a.pop()
        b.append(element)
        p_value_b = recursive_permutation_test(data, a, b)
        b.pop()
        return max(p_value_a, p_value_b)

def main():
    data = [random.randint(1, 100) for _ in range(20)]
    a = []
    b = []
    while True:
        p_value = recursive_permutation_test(data.copy(), a.copy(), b.copy())
        print(p_value)
main()