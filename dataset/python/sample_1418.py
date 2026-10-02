class FlightData:

    def __init__(self, altitude, speed, heading):
        self.altitude = altitude
        self.speed = speed
        self.heading = heading

    def update_altitude(self, new_altitude):
        self.altitude = new_altitude

    def update_speed(self, new_speed):
        self.speed = new_speed

    def update_heading(self, new_heading):
        self.heading = new_heading

def calculate_new_altitude(current_altitude, target_altitude, step):
    if current_altitude < target_altitude:
        return min(current_altitude + step, target_altitude)
    return max(current_altitude - step, target_altitude)

def calculate_new_speed(current_speed, target_speed, step):
    if current_speed < target_speed:
        return min(current_speed + step, target_speed)
    return max(current_speed - step, target_speed)

def cruise_altitude_planning(flight, target_altitude, target_speed, step):
    while flight.altitude != target_altitude or flight.speed != target_speed:
        flight.update_altitude(calculate_new_altitude(flight.altitude, target_altitude, step))
        flight.update_speed(calculate_new_speed(flight.speed, target_speed, step))

def main():
    initial_altitude = 10000
    initial_speed = 800
    initial_heading = 90
    target_altitude = 30000
    target_speed = 900
    step = 1000
    flight = FlightData(initial_altitude, initial_speed, initial_heading)
    cruise_altitude_planning(flight, target_altitude, target_speed, step)
    print(f'Final altitude: {flight.altitude}, Final speed: {flight.speed}')
main()