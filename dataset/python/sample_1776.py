def calculate_altitude_profile(cruise_altitude, max_altitude, step):
    altitude_list = []
    current_altitude = 0
    while current_altitude < max_altitude:
        altitude_list.append(current_altitude)
        if current_altitude < cruise_altitude:
            current_altitude += step
        else:
            current_altitude -= step
    return altitude_list

def adjust_flight_path(altitude_profile, wind_factor):
    adjusted_profile = []
    for altitude in altitude_profile:
        adjusted_altitude = altitude + wind_factor
        adjusted_profile.append(adjusted_altitude)
    return adjusted_profile

def optimize_trajectory(trajectory, target_altitude):
    optimized_trajectory = []
    for altitude in trajectory:
        if altitude < target_altitude:
            optimized_trajectory.append(target_altitude)
        else:
            optimized_trajectory.append(altitude)
    return optimized_trajectory

def main():
    cruise_altitude = 30000
    max_altitude = 40000
    step = 1000
    wind_factor = 500
    target_altitude = 35000
    altitude_profile = calculate_altitude_profile(cruise_altitude, max_altitude, step)
    adjusted_profile = adjust_flight_path(altitude_profile, wind_factor)
    optimized_trajectory = optimize_trajectory(adjusted_profile, target_altitude)
    print(optimized_trajectory)
main()