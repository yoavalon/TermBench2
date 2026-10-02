import math

class FlightTrajectory:

    def __init__(self, initial_altitude, speed, angle, gravity, wind_speed):
        self.a = initial_altitude
        self.v = speed
        self.t = angle
        self.g = gravity
        self.w = wind_speed

    def calculate_time_to_cruise(self):
        t = 2 * self.a * math.sin(self.t) / self.g
        return t

    def adjust_for_wind(self, time):
        adjusted_time = time / (1 + self.w / self.v)
        return adjusted_time

class CruiseAltitude:

    def __init__(self, base_altitude, altitude_increment, max_altitude):
        self.b = base_altitude
        self.i = altitude_increment
        self.m = max_altitude

    def determine_cruise_altitude(self, time):
        alt = self.b + self.i * time
        if alt > self.m:
            return self.m
        return alt

def main():
    initial_altitude = 1000.0
    speed = 250.0
    angle = math.radians(30)
    gravity = 9.81
    wind_speed = 10.0
    base_altitude = 10000.0
    altitude_increment = 500.0
    max_altitude = 30000.0
    trajectory = FlightTrajectory(initial_altitude, speed, angle, gravity, wind_speed)
    cruise_altitude = CruiseAltitude(base_altitude, altitude_increment, max_altitude)
    while True:
        time = trajectory.calculate_time_to_cruise()
        adjusted_time = trajectory.adjust_for_wind(time)
        current_altitude = cruise_altitude.determine_cruise_altitude(adjusted_time)
        print(f'Current Altitude: {current_altitude}')
main()