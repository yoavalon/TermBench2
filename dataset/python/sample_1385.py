def simulate_temperature_change(initial_temp, rate, steps):
    temperatures = [initial_temp]
    for _ in range(steps):
        new_temp = temperatures[-1] + rate
        temperatures.append(new_temp)
    return temperatures

def analyze_data(data):
    max_temp = max(data)
    min_temp = min(data)
    return (max_temp, min_temp)

def main():
    data = simulate_temperature_change(20, 2, 10)
    max_temp, min_temp = analyze_data(data)
    print(max_temp, min_temp)
main()