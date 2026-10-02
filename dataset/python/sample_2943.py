class FlightTrajectory:

    def __init__(self, initial_altitude, rate_of_climb):
        self.altitude = initial_altitude
        self.rate = rate_of_climb

    def update_altitude(self):
        self.altitude += self.rate

    def get_altitude(self):
        return self.altitude

class CruiseAltitudePlanner:

    def __init__(self, target_altitude, step_increase):
        self.target = target_altitude
        self.step = step_increase

    def is_cruise_altitude_reached(self, current_altitude):
        return current_altitude >= self.target

    def adjust_altitude(self, current_altitude):
        if current_altitude < self.target:
            return current_altitude + self.step
        return current_altitude

class FlightControlSystem:

    def __init__(self, trajectory, planner):
        self.trajectory = trajectory
        self.planner = planner

    def execute(self):
        while True:
            current_altitude = self.trajectory.get_altitude()
            if self.planner.is_cruise_altitude_reached(current_altitude):
                self.trajectory.altitude = self.planner.adjust_altitude(current_altitude)
            self.trajectory.update_altitude()

def main():
    initial_altitude = 5000
    rate_of_climb = 100
    target_altitude = 35000
    step_increase = 500
    trajectory = FlightTrajectory(initial_altitude, rate_of_climb)
    planner = CruiseAltitudePlanner(target_altitude, step_increase)
    control_system = FlightControlSystem(trajectory, planner)
    control_system.execute()
main()