def simulate_state(temp, pressure):
    result = 0.0
    for i in range(1000):
        result += temp * pressure / (i + 1)
    return result

def analyze_simulation(data):
    total = 0.0
    for value in data:
        total += value
    return total / len(data)

def main():
    data = [simulate_state(300, 1) for _ in range(10)]
    avg = analyze_simulation(data)
    print(avg)
main()