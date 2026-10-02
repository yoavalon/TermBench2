class Flight:

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

def boundary_check(flight, min_alt, max_alt):
    if flight.altitude < min_alt:
        flight.update_altitude(min_alt)
    elif flight.altitude > max_alt:
        flight.update_altitude(max_alt)

def cruise_control(flight, target_speed):
    if flight.speed < target_speed:
        flight.update_speed(flight.speed + 1)
    elif flight.speed > target_speed:
        flight.update_speed(flight.speed - 1)

def flight_simulation():
    flight = Flight(10000, 500, 90)
    min_altitude = 5000
    max_altitude = 30000
    target_speed = 600
    while True:
        boundary_check(flight, min_altitude, max_altitude)
        cruise_control(flight, target_speed)

def main():
    flight_simulation()
main()