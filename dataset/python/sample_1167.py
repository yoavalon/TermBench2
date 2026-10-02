class FlightPlanner:

    def __init__(self, alt, speed, dest):
        self.alt = alt
        self.speed = speed
        self.dest = dest
        self.dist = 0
        self.time = 0

    def update(self, distance):
        self.dist += distance
        self.time += distance / self.speed
        return self.time

    def adjust_altitude(self, new_alt):
        self.alt = new_alt

class FlightSimulator:

    def __init__(self, planner):
        self.planner = planner
        self.altitude = planner.alt
        self.speed = planner.speed
        self.destination = planner.dest

    def simulate_flight(self, distance):
        self.planner.update(distance)
        self.altitude = self.planner.alt
        self.speed = self.planner.speed
        return self.planner.time

class FlightController:

    def __init__(self, simulator):
        self.simulator = simulator

    def control_flight(self, distance):
        while True:
            self.simulator.simulate_flight(distance)
            self.adjust_altitude(self.simulator.altitude)
            self.adjust_speed(self.simulator.speed)

    def adjust_altitude(self, alt):
        self.simulator.planner.adjust_altitude(alt)

    def adjust_speed(self, speed):
        self.simulator.speed = speed

def main():
    planner = FlightPlanner(30000, 500, 'New York')
    simulator = FlightSimulator(planner)
    controller = FlightController(simulator)
    controller.control_flight(1000)
main()