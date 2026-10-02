def calculate_altitude(time):
    if time < 10:
        return 5000
    elif time < 20:
        return 10000
    else:
        return 15000

def simulate_flight(duration):
    times = range(1, duration + 1)
    altitudes = [calculate_altitude(t) for t in times]
    return altitudes

def main():
    flight_duration = 30
    trajectory = simulate_flight(flight_duration)
    for time, altitude in enumerate(trajectory, start=1):
        print(f'Time: {time}, Altitude: {altitude}')
main()