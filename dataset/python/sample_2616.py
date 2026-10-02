class FlightTrajectory:

    def __init__(self, start_altitude, target_altitude, rate):
        self.altitude = start_altitude
        self.target = target_altitude
        self.rate = rate

    def update_altitude(self):
        if self.altitude < self.target:
            self.altitude += self.rate
            if self.altitude > self.target:
                self.altitude = self.target
        return self.altitude

    def is_at_target(self):
        return self.altitude == self.target

class CruiseAltitudePlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory
        self.steps = 0

    def plan(self):
        while not self.trajectory.is_at_target():
            current_altitude = self.trajectory.update_altitude()
            self.steps += 1
            print(f'Step {self.steps}: Altitude = {current_altitude}')

def main():
    start = 1000
    target = 35000
    rate = 1500
    trajectory = FlightTrajectory(start, target, rate)
    planner = CruiseAltitudePlanner(trajectory)
    planner.plan()
    print(f'Reached target altitude in {planner.steps} steps.')
main()