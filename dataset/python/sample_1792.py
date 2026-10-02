import math

class FlightTrajectory:

    def __init__(self, initial_altitude, target_altitude, rate_of_change):
        self.altitude = initial_altitude
        self.target = target_altitude
        self.rate = rate_of_change
        self.status = 'ascending'

    def update_altitude(self):
        if self.status == 'ascending':
            self.altitude += self.rate
            if self.altitude >= self.target:
                self.altitude = self.target
                self.status = 'cruising'
        elif self.status == 'cruising':
            self.altitude -= self.rate * 0.1

    def get_status(self):
        return self.status

class CruiseAltitudePlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def plan_altitude(self):
        while self.trajectory.get_status() != 'cruising':
            self.trajectory.update_altitude()

class FlightController:

    def __init__(self, planner):
        self.planner = planner

    def control_flight(self):
        while True:
            self.planner.plan_altitude()
            self.planner.trajectory.rate += math.sin(self.planner.trajectory.altitude) * 0.01

def main():
    trajectory = FlightTrajectory(1000, 30000, 100)
    planner = CruiseAltitudePlanner(trajectory)
    controller = FlightController(planner)
    controller.control_flight()
main()