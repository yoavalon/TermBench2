def calculate_altitude_sequence(initial_altitude, increment, steps):
    sequence = []
    for i in range(steps):
        sequence.append(initial_altitude + i * increment)
    return sequence

def find_optimal_cruise_altitude(altitudes, max_fuel_consumption):
    optimal_altitude = max(altitudes, key=lambda x: x <= max_fuel_consumption)
    return optimal_altitude

def main():
    initial = 10000
    increment = 1000
    steps = 10
    max_fuel = 15000
    altitudes = calculate_altitude_sequence(initial, increment, steps)
    optimal_altitude = find_optimal_cruise_altitude(altitudes, max_fuel)
    print(optimal_altitude)
main()