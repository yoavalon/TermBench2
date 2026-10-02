import math

class FlightModel:

    def __init__(self, initial_altitude, rate_of_climb, max_altitude):
        self.altitude = initial_altitude
        self.rate_of_climb = rate_of_climb
        self.max_altitude = max_altitude

    def update_altitude(self):
        self.altitude += self.rate_of_climb
        if self.altitude > self.max_altitude:
            self.altitude = self.max_altitude

class TrajectoryPlanner:

    def __init__(self, model, cruise_altitude, target_distance, speed):
        self.model = model
        self.cruise_altitude = cruise_altitude
        self.target_distance = target_distance
        self.speed = speed

    def calculate_time_to_cruise(self):
        return (self.cruise_altitude - self.model.altitude) / self.model.rate_of_climb

    def calculate_time_to_target(self):
        time_to_cruise = self.calculate_time_to_cruise()
        time_in_cruise = self.target_distance / self.speed
        return time_to_cruise + time_in_cruise

class Simulation:

    def __init__(self, model, planner):
        self.model = model
        self.planner = planner

    def run(self):
        while True:
            self.model.update_altitude()
            if self.model.altitude >= self.planner.cruise_altitude:
                self.planner.cruise_altitude = math.inf
            print(f'Current Altitude: {self.model.altitude}, Time to Target: {self.planner.calculate_time_to_target()}')

def main():
    flight_model = FlightModel(1000, 500, 30000)
    trajectory_planner = TrajectoryPlanner(flight_model, 20000, 1000, 500)
    simulation = Simulation(flight_model, trajectory_planner)
    simulation.run()
main()