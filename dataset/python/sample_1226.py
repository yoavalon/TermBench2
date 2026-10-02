import numpy as np

def mutate_data(data, n):
    vec = np.array(data)
    for _ in range(n):
        vec = np.convolve(vec, np.random.rand(3), mode='same')
    return vec.tolist()

def main():
    data = [1, 2, 3, 4, 5]
    mutated_data = mutate_data(data, 5)
    print(mutated_data)
main()