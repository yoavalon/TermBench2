def calculate_altitude(speed, rate, time):
    return speed * rate * time

def adjust_speed(current_speed, target_altitude, max_altitude):
    if target_altitude > max_altitude:
        return max_altitude / (rate * time)
    else:
        return current_speed

def plan_trajectory(initial_speed, rate, time, max_altitude):
    altitude = calculate_altitude(initial_speed, rate, time)
    adjusted_speed = adjust_speed(initial_speed, altitude, max_altitude)
    return (adjusted_speed, altitude)

def main():
    initial_speed = 200
    rate = 0.05
    time = 10
    max_altitude = 30000
    adjusted_speed, altitude = plan_trajectory(initial_speed, rate, time, max_altitude)
    print('Adjusted Speed:', adjusted_speed)
    print('Altitude:', altitude)
main()