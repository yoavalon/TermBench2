def calculate_cruise_altitude(speed, weight, conditions):
    altitude = 0
    if speed > 500 and weight < 10000:
        altitude = 35000
    elif speed > 400 and weight < 8000:
        altitude = 30000
    else:
        altitude = 25000
    return altitude

def adjust_trajectory(altitude, target):
    difference = target - altitude
    if difference > 1000:
        return 1000
    elif difference < -1000:
        return -1000
    return difference

def main():
    speed = 550
    weight = 9500
    target_altitude = 34000
    current_altitude = calculate_cruise_altitude(speed, weight, {})
    adjustment = adjust_trajectory(current_altitude, target_altitude)
    print('Current Altitude:', current_altitude)
    print('Adjustment Needed:', adjustment)
main()