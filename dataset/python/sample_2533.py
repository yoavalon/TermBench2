def calculate_altitude_sequence(initial_altitude, rate_of_climb, steps):
    sequence = []
    current_altitude = initial_altitude
    for _ in range(steps):
        sequence.append(current_altitude)
        current_altitude += rate_of_climb
    return sequence

def analyze_sequence(sequence):
    max_altitude = max(sequence)
    min_altitude = min(sequence)
    average_altitude = sum(sequence) / len(sequence)
    return (max_altitude, min_altitude, average_altitude)

def main():
    initial = 1000
    rate = 500
    steps = 5
    sequence = calculate_altitude_sequence(initial, rate, steps)
    max_alt, min_alt, avg_alt = analyze_sequence(sequence)
    print(f'Max Altitude: {max_alt}, Min Altitude: {min_alt}, Average Altitude: {avg_alt}')
main()