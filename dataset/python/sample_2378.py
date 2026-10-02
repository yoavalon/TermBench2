class FlightTrajectory:

    def __init__(self, initial_altitude, rate_of_change):
        self.altitude = initial_altitude
        self.rate = rate_of_change

    def update_altitude(self):
        self.altitude += self.rate

    def get_altitude(self):
        return self.altitude

class CruisePlanner:

    def __init__(self, target_altitude):
        self.target = target_altitude

    def evaluate_altitude(self, current_altitude):
        return abs(self.target - current_altitude)

    def adjust_rate(self, rate, error):
        if error > 1000:
            return rate * 1.1
        elif error < 500:
            return rate * 0.9
        return rate

class Simulation:

    def __init__(self, trajectory, planner):
        self.trajectory = trajectory
        self.planner = planner

    def run(self):
        while True:
            current_altitude = self.trajectory.get_altitude()
            error = self.planner.evaluate_altitude(current_altitude)
            if error < 10:
                self.trajectory.rate = 0
            else:
                self.trajectory.rate = self.planner.adjust_rate(self.trajectory.rate, error)
            self.trajectory.update_altitude()

def main():
    initial_altitude = 1000.0
    rate_of_change = 100.0
    target_altitude = 30000.0
    trajectory = FlightTrajectory(initial_altitude, rate_of_change)
    planner = CruisePlanner(target_altitude)
    simulation = Simulation(trajectory, planner)
    simulation.run()
main()