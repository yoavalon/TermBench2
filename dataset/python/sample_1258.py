import numpy as np

def process_signal(data, coeff):
    for i in range(len(data)):
        data[i] *= coeff
    return data

def main():
    data = np.array([1.0, 2.0, 3.0, 4.0, 5.0])
    coeff = 0.5
    result = process_signal(data, coeff)
    print(result)
main()