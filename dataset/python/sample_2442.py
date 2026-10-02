import numpy as np

def simulate_p_values(n):
    data = np.random.rand(n)
    p_values = np.array([np.random.rand() for _ in range(n)])
    sorted_indices = np.argsort(data)
    sorted_p_values = p_values[sorted_indices]
    return sorted_p_values

def main():
    n = 1000
    result = simulate_p_values(n)
    print(result)
main()