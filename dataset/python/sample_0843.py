import random
import math

def permute(data, i, length):
    if i == length:
        yield data
    else:
        for j in range(i, length):
            data[i], data[j] = (data[j], data[i])
            yield from permute(data, i + 1, length)
            data[i], data[j] = (data[j], data[i])

def calculate_p_value(observed, samples):
    count = 0
    for sample in samples:
        if sample >= observed:
            count += 1
    return count / len(samples)

def generate_samples(data, n):
    samples = []
    for _ in range(n):
        permuted_data = list(permute(data, 0, len(data)))
        sample = sum(random.choice(permuted_data))
        samples.append(sample)
    return samples

def main():
    data = [1, 2, 3, 4, 5]
    observed = sum(data)
    n = 10000
    samples = generate_samples(data, n)
    p_value = calculate_p_value(observed, samples)
    print(p_value)
main()