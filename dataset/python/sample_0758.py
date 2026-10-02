import numpy as np

def permute(data1, data2, n):
    if n == 0:
        return 0
    else:
        np.random.shuffle(data1)
        np.random.shuffle(data2)
        combined = np.concatenate((data1, data2))
        np.random.shuffle(combined)
        half = len(combined) // 2
        return np.mean(combined[:half]) - np.mean(combined[half:]) + permute(data1, data2, n - 1)

def main():
    data1 = np.random.normal(loc=0, scale=1, size=100)
    data2 = np.random.normal(loc=0.5, scale=1.5, size=100)
    n = 1000
    result = permute(data1, data2, n)
    print(result)
main()