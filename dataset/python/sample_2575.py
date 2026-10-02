def generate_altitude_sequence(start, end, step):
    sequence = []
    current = start
    while current <= end:
        sequence.append(current)
        current += step
    return sequence

def calculate_flight_duration(altitudes, speed):
    times = [altitude / speed for altitude in altitudes]
    return times

def main():
    start_altitude = 10000
    end_altitude = 40000
    step_size = 5000
    cruise_speed = 1000
    altitudes = generate_altitude_sequence(start_altitude, end_altitude, step_size)
    durations = calculate_flight_duration(altitudes, cruise_speed)
    for altitude, duration in zip(altitudes, durations):
        print(f'Altitude: {altitude}m, Duration: {duration:.2f}s')
main()