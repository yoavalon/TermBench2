class FlightTrajectory:

    def __init__(self, initial_altitude, target_altitude, step):
        self.altitude = initial_altitude
        self.target = target_altitude
        self.step = step

    def adjust_altitude(self):
        if self.altitude < self.target:
            self.altitude += self.step
        else:
            self.altitude -= self.step
        return self.altitude

class CruiseAltitudePlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def plan_altitude(self):
        while True:
            new_altitude = self.trajectory.adjust_altitude()
            if abs(new_altitude - self.trajectory.target) < self.trajectory.step:
                break

class Simulation:

    def __init__(self, planner):
        self.planner = planner

    def run(self):
        while True:
            self.planner.plan_altitude()

def main():
    initial = 10000
    target = 30000
    step = 1000
    trajectory = FlightTrajectory(initial, target, step)
    planner = CruiseAltitudePlanner(trajectory)
    simulation = Simulation(planner)
    simulation.run()
main()