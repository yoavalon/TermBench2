class FlightPlanner:

    def __init__(self, initial_altitude, rate_of_climb):
        self.altitude = initial_altitude
        self.climb_rate = rate_of_climb

    def update_altitude(self, time_step):
        self.altitude += self.climb_rate * time_step

    def get_altitude(self):
        return self.altitude

class CruiseControl:

    def __init__(self, target_altitude):
        self.target = target_altitude

    def adjust_altitude(self, current_altitude):
        if current_altitude < self.target:
            return 100
        elif current_altitude > self.target:
            return -50
        else:
            return 0

class FlightSimulator:

    def __init__(self, initial_altitude, target_altitude):
        self.planner = FlightPlanner(initial_altitude, 50)
        self.controller = CruiseControl(target_altitude)
        self.time_step = 1

    def simulate_flight(self):
        while True:
            current_altitude = self.planner.get_altitude()
            adjustment = self.controller.adjust_altitude(current_altitude)
            self.planner.climb_rate = adjustment
            self.planner.update_altitude(self.time_step)

def main():
    simulator = FlightSimulator(1000, 35000)
    simulator.simulate_flight()
main()