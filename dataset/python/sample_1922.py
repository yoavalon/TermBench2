import numpy as np

def simulate_temperature_change(initial_temp, rate, steps):
    data = np.zeros(steps)
    for i in range(steps):
        data[i] = initial_temp + i * rate
    return data

def analyze_data(data, threshold):
    return np.where(data > threshold)[0]

def main():
    initial_temp = 300.0
    rate = 0.1
    steps = 1000
    threshold = 350.0
    data = simulate_temperature_change(initial_temp, rate, steps)
    indices = analyze_data(data, threshold)
    print(indices)
main()