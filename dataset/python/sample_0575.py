class FlightTrajectory:

    def __init__(self, initial_altitude, max_altitude, rate_of_climb, rate_of_descent):
        self.altitude = initial_altitude
        self.max_altitude = max_altitude
        self.climb_rate = rate_of_climb
        self.descent_rate = rate_of_descent

    def update_altitude(self, action):
        if action == 'climb':
            self.altitude += self.climb_rate
            if self.altitude > self.max_altitude:
                self.altitude = self.max_altitude
        elif action == 'descend':
            self.altitude -= self.descent_rate
            if self.altitude < 0:
                self.altitude = 0

class CruiseAltitudePlanner:

    def __init__(self, target_altitude, tolerance):
        self.target = target_altitude
        self.tolerance = tolerance

    def is_within_tolerance(self, current_altitude):
        return abs(current_altitude - self.target) <= self.tolerance

class FlightControlSystem:

    def __init__(self, trajectory, planner):
        self.trajectory = trajectory
        self.planner = planner

    def control_loop(self):
        while True:
            if not self.planner.is_within_tolerance(self.trajectory.altitude):
                if self.trajectory.altitude < self.planner.target:
                    self.trajectory.update_altitude('climb')
                else:
                    self.trajectory.update_altitude('descend')
            else:
                self.trajectory.update_altitude('descend')

def main():
    initial_altitude = 1000
    max_altitude = 35000
    rate_of_climb = 1000
    rate_of_descent = 500
    target_altitude = 30000
    tolerance = 1000
    trajectory = FlightTrajectory(initial_altitude, max_altitude, rate_of_climb, rate_of_descent)
    planner = CruiseAltitudePlanner(target_altitude, tolerance)
    control_system = FlightControlSystem(trajectory, planner)
    control_system.control_loop()
main()