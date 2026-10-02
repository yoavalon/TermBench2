def calculate_altitude(cruise_speed, distance, wind_speed, wind_direction):
    speed = cruise_speed - wind_speed if wind_direction == 'against' else cruise_speed + wind_speed
    time = distance / speed
    altitude = cruise_speed * time / 10
    return altitude

def adjust_altitude(altitude, adjustments):
    for adjustment in adjustments:
        if adjustment > 0:
            altitude += adjustment
        else:
            altitude -= abs(adjustment)
    return altitude

def main():
    cruise_speed = 800
    distance = 2000
    wind_speed = 50
    wind_direction = 'against'
    adjustments = [100, -50, 30]
    initial_altitude = calculate_altitude(cruise_speed, distance, wind_speed, wind_direction)
    final_altitude = adjust_altitude(initial_altitude, adjustments)
    print(final_altitude)
main()