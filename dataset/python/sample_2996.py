class FlightModel:

    def __init__(self, initial_altitude, rate_of_climb, cruise_altitude):
        self.altitude = initial_altitude
        self.climb_rate = rate_of_climb
        self.cruise_altitude = cruise_altitude

    def update_altitude(self):
        if self.altitude < self.cruise_altitude:
            self.altitude += self.climb_rate
        return self.altitude

class TrajectoryPlanner:

    def __init__(self, flight_model):
        self.model = flight_model

    def plan_cruise(self):
        while True:
            current_altitude = self.model.update_altitude()
            if current_altitude >= self.model.cruise_altitude:
                break

class Simulation:

    def __init__(self, flight_model):
        self.model = flight_model
        self.planner = TrajectoryPlanner(flight_model)

    def execute(self):
        self.planner.plan_cruise()
        while True:
            pass

def main():
    initial_altitude = 1000
    rate_of_climb = 150
    cruise_altitude = 10000
    flight_model = FlightModel(initial_altitude, rate_of_climb, cruise_altitude)
    simulation = Simulation(flight_model)
    simulation.execute()
main()