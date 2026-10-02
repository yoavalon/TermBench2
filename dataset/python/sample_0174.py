def calculate_pressure(temperature, volume):
    return 0.0821 * temperature / volume

def update_temperature(temp, heat_added, heat_capacity):
    return temp + heat_added / heat_capacity

def main():
    temp = 300
    vol = 22.4
    heat_cap = 25
    heat_added = 1000
    max_iterations = 10
    for _ in range(max_iterations):
        pressure = calculate_pressure(temp, vol)
        temp = update_temperature(temp, heat_added, heat_cap)
        print(f'Pressure: {pressure:.2f} atm, Temperature: {temp:.2f} K')
main()