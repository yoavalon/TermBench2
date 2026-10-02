class FlightPlanner:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb, max_altitude):
        self.current_altitude = initial_altitude
        self.target_altitude = target_altitude
        self.rate_of_climb = rate_of_climb
        self.max_altitude = max_altitude

    def climb(self):
        if self.current_altitude < self.target_altitude:
            self.current_altitude += self.rate_of_climb
            if self.current_altitude > self.max_altitude:
                self.current_altitude = self.max_altitude

    def stabilize(self):
        if self.current_altitude == self.target_altitude:
            return True
        return False

    def plan_flight(self):
        while not self.stabilize():
            self.climb()
        return self.current_altitude

class FlightData:

    def __init__(self, altitudes):
        self.altitudes = altitudes

    def update_altitude(self, new_altitude):
        self.altitudes.append(new_altitude)

    def get_altitudes(self):
        return self.altitudes

class FlightController:

    def __init__(self, planner, data):
        self.planner = planner
        self.data = data

    def execute_flight(self):
        final_altitude = self.planner.plan_flight()
        self.data.update_altitude(final_altitude)
        return self.data.get_altitudes()

def main():
    initial_altitude = 5000
    target_altitude = 35000
    rate_of_climb = 1000
    max_altitude = 40000
    planner = FlightPlanner(initial_altitude, target_altitude, rate_of_climb, max_altitude)
    data = FlightData([initial_altitude])
    controller = FlightController(planner, data)
    altitudes = controller.execute_flight()
    print(altitudes)
main()