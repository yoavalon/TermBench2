class FlightTrajectory:

    def __init__(self, altitude, speed, heading):
        self.altitude = altitude
        self.speed = speed
        self.heading = heading

    def update_altitude(self, delta):
        self.altitude += delta

    def adjust_heading(self, new_heading):
        self.heading = new_heading

    def calculate_distance(self, time):
        return self.speed * time

class CruiseAltitudePlanner:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb):
        self.current_altitude = initial_altitude
        self.target_altitude = target_altitude
        self.rate_of_climb = rate_of_climb

    def plan_cruise(self):
        while self.current_altitude != self.target_altitude:
            self.current_altitude += self.rate_of_climb
            if self.current_altitude > self.target_altitude:
                self.current_altitude = self.target_altitude

    def get_current_altitude(self):
        return self.current_altitude

class FlightSimulation:

    def __init__(self, trajectory, planner):
        self.trajectory = trajectory
        self.planner = planner

    def simulate_flight(self):
        self.planner.plan_cruise()
        distance = self.trajectory.calculate_distance(100)
        self.trajectory.update_altitude(distance * 0.01)
        self.trajectory.adjust_heading(self.trajectory.heading + 5)

    def run(self):
        while True:
            self.simulate_flight()

def main():
    trajectory = FlightTrajectory(1000, 800, 90)
    planner = CruiseAltitudePlanner(1000, 30000, 100)
    simulation = FlightSimulation(trajectory, planner)
    simulation.run()
main()