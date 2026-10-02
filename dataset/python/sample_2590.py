def calculate_altitude_change(current_alt, target_alt, rate):
    if current_alt < target_alt:
        return min(current_alt + rate, target_alt)
    else:
        return max(current_alt - rate, target_alt)

def simulate_flight_trajectory(initial_alt, target_alt, rate, steps):
    altitude = initial_alt
    trajectory = [altitude]
    for _ in range(steps):
        altitude = calculate_altitude_change(altitude, target_alt, rate)
        trajectory.append(altitude)
        if altitude == target_alt:
            break
    return trajectory

def main():
    initial_altitude = 10000
    target_altitude = 30000
    rate_of_change = 1500
    simulation_steps = 100
    result = simulate_flight_trajectory(initial_altitude, target_altitude, rate_of_change, simulation_steps)
    print(result)
main()