import math

class TrajectoryPlanner:

    def __init__(self, initial_altitude, speed, wind_speed, wind_direction):
        self.altitude = initial_altitude
        self.speed = speed
        self.wind_speed = wind_speed
        self.wind_direction = wind_direction

    def calculate_distance(self, time):
        distance = self.speed * time
        wind_effect = self.wind_speed * math.cos(math.radians(self.wind_direction - 90))
        return distance + wind_effect

    def update_altitude(self, time, rate_of_climb):
        climb_distance = rate_of_climb * time
        self.altitude += climb_distance

class CruiseManager:

    def __init__(self, target_altitude, max_altitude):
        self.target_altitude = target_altitude
        self.max_altitude = max_altitude

    def should_adjust_altitude(self, current_altitude):
        return current_altitude < self.target_altitude

    def calculate_rate_of_climb(self, current_altitude):
        return (self.target_altitude - current_altitude) / 10

def main():
    initial_altitude = 1000
    speed = 250
    wind_speed = 20
    wind_direction = 45
    trajectory = TrajectoryPlanner(initial_altitude, speed, wind_speed, wind_direction)
    cruise_manager = CruiseManager(15000, 20000)
    time_step = 60
    while True:
        distance = trajectory.calculate_distance(time_step)
        if cruise_manager.should_adjust_altitude(trajectory.altitude):
            rate_of_climb = cruise_manager.calculate_rate_of_climb(trajectory.altitude)
            trajectory.update_altitude(time_step, rate_of_climb)
        print(f'Distance: {distance:.2f}m, Altitude: {trajectory.altitude:.2f}m')
main()