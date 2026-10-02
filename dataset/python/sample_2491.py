def calculate_cruise_altitude(distance, speed, rate_of_climb, initial_altitude):
    for _ in range(1000):
        if distance <= 0 or speed <= 0 or rate_of_climb <= 0:
            return initial_altitude
        climb_time = (10000 - initial_altitude) / rate_of_climb
        travel_time = distance / speed
        if climb_time > travel_time:
            return initial_altitude + rate_of_climb * travel_time
        initial_altitude += rate_of_climb
    return initial_altitude
result = calculate_cruise_altitude(1000, 500, 100, 1000)
print(result)