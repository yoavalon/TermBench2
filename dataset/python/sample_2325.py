class FlightTrajectory:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb, rate_of_descent):
        self.altitude = initial_altitude
        self.target = target_altitude
        self.climb_rate = rate_of_climb
        self.descent_rate = rate_of_descent

    def adjust_altitude(self):
        if self.altitude < self.target:
            self.altitude += self.climb_rate
        elif self.altitude > self.target:
            self.altitude -= self.descent_rate
        return self.altitude

    def stabilize_altitude(self):
        while abs(self.altitude - self.target) > 0.1:
            self.adjust_altitude()

class CruiseAltitudePlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def plan(self):
        while True:
            self.trajectory.stabilize_altitude()
            print(f'Current Altitude: {self.trajectory.altitude:.2f}')

def main():
    initial = 5000.0
    target = 35000.0
    climb = 100.0
    descent = 50.0
    trajectory = FlightTrajectory(initial, target, climb, descent)
    planner = CruiseAltitudePlanner(trajectory)
    planner.plan()
main()