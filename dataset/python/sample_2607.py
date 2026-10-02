def calculate_altitude_profile(distance, speed, rate_of_climb, cruise_altitude, descent_rate):
    times = []
    altitudes = []
    current_time = 0
    current_altitude = 0
    while current_time < distance / speed:
        if current_altitude < rate_of_climb * current_time:
            current_altitude = rate_of_climb * current_time
        elif current_altitude < cruise_altitude:
            current_altitude = cruise_altitude
        else:
            current_altitude -= descent_rate * (current_time - cruise_altitude / rate_of_climb)
        times.append(current_time)
        altitudes.append(current_altitude)
        current_time += 1
    return (times, altitudes)

def analyze_flight_profile(times, altitudes):
    max_altitude = max(altitudes)
    cruise_start_time = times[altitudes.index(cruise_altitude)]
    descent_start_time = times[-1]
    return (max_altitude, cruise_start_time, descent_start_time)

def main():
    distance = 1000
    speed = 800
    rate_of_climb = 100
    cruise_altitude = 10000
    descent_rate = 50
    times, altitudes = calculate_altitude_profile(distance, speed, rate_of_climb, cruise_altitude, descent_rate)
    max_altitude, cruise_start_time, descent_start_time = analyze_flight_profile(times, altitudes)
    print(f'Maximum Altitude: {max_altitude} meters')
    print(f'Cruise Start Time: {cruise_start_time} seconds')
    print(f'Descent Start Time: {descent_start_time} seconds')
if __name__ == '__main__':
    main()