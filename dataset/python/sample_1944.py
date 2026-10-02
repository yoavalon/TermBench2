def calculate_altitude_change(current_altitude, target_altitude, rate):
    change = target_altitude - current_altitude
    if abs(change) < rate:
        return target_altitude
    return current_altitude + rate * (1 if change > 0 else -1)

def plan_trajectory(initial_altitude, target_altitude, rate, steps):
    altitudes = []
    current_altitude = initial_altitude
    for _ in range(steps):
        current_altitude = calculate_altitude_change(current_altitude, target_altitude, rate)
        altitudes.append(current_altitude)
    return altitudes

def main():
    initial_altitude = 3000.0
    target_altitude = 3500.0
    rate = 100.0
    steps = 10
    trajectory = plan_trajectory(initial_altitude, target_altitude, rate, steps)
    print(trajectory)
main()