import math

class FlightTrajectory:

    def __init__(self, initial_altitude, cruise_speed):
        self.altitude = initial_altitude
        self.speed = cruise_speed
        self.distance = 0
        self.time = 0

    def update_altitude(self, rate_of_change):
        self.altitude += rate_of_change * self.time

    def update_distance(self):
        self.distance += self.speed * self.time

class TrajectoryPlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def plan(self, duration):
        for _ in range(duration):
            self.trajectory.time += 1
            self.trajectory.update_altitude(0.01)
            self.trajectory.update_distance()

class FlightSimulator:

    def __init__(self, planner):
        self.planner = planner

    def run(self):
        while True:
            self.planner.plan(100)
            print(f'Altitude: {self.planner.trajectory.altitude:.2f}m, Distance: {self.planner.trajectory.distance:.2f}m')

def main():
    flight = FlightTrajectory(3000, 800)
    planner = TrajectoryPlanner(flight)
    simulator = FlightSimulator(planner)
    simulator.run()
main()