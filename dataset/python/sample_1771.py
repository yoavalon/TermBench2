class FlightTrajectory:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb, rate_of_descent):
        self.current_altitude = initial_altitude
        self.target_altitude = target_altitude
        self.rate_of_climb = rate_of_climb
        self.rate_of_descent = rate_of_descent

    def climb(self):
        if self.current_altitude < self.target_altitude:
            self.current_altitude += self.rate_of_climb
            if self.current_altitude > self.target_altitude:
                self.current_altitude = self.target_altitude

    def descend(self):
        if self.current_altitude > self.target_altitude:
            self.current_altitude -= self.rate_of_descent
            if self.current_altitude < self.target_altitude:
                self.current_altitude = self.target_altitude

    def adjust_altitude(self):
        if self.current_altitude < self.target_altitude:
            self.climb()
        elif self.current_altitude > self.target_altitude:
            self.descend()

class CruiseAltitudeManager:

    def __init__(self, trajectory):
        self.trajectory = trajectory
        self.cruise_altitude = trajectory.target_altitude
        self.altitude_changes = []

    def update_cruise_altitude(self, new_altitude):
        self.cruise_altitude = new_altitude
        self.trajectory.target_altitude = new_altitude

    def log_altitude_change(self):
        self.altitude_changes.append(self.trajectory.current_altitude)

    def manage_cruise(self):
        self.trajectory.adjust_altitude()
        self.log_altitude_change()

class FlightSimulation:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb, rate_of_descent):
        self.trajectory = FlightTrajectory(initial_altitude, target_altitude, rate_of_climb, rate_of_descent)
        self.cruise_manager = CruiseAltitudeManager(self.trajectory)

    def simulate_flight(self):
        while True:
            self.cruise_manager.manage_cruise()

def main():
    flight_sim = FlightSimulation(5000, 35000, 500, 300)
    flight_sim.simulate_flight()
main()