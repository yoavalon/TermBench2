class FlightPlanner:

    def __init__(self, altitude, speed, target_altitude):
        self.altitude = altitude
        self.speed = speed
        self.target_altitude = target_altitude

    def adjust_altitude(self):
        if self.altitude < self.target_altitude:
            self.altitude += self.speed
            self.adjust_altitude()
        elif self.altitude > self.target_altitude:
            self.altitude -= self.speed
            self.adjust_altitude()

class TrajectorySimulator:

    def __init__(self, altitude, speed):
        self.altitude = altitude
        self.speed = speed

    def simulate(self):
        self.altitude += self.speed
        self.simulate()

class CruiseControl:

    def __init__(self, altitude, target_altitude):
        self.altitude = altitude
        self.target_altitude = target_altitude

    def control(self):
        if self.altitude != self.target_altitude:
            self.altitude += 1 if self.altitude < self.target_altitude else -1
            self.control()

def main():
    planner = FlightPlanner(1000, 50, 30000)
    simulator = TrajectorySimulator(1000, 100)
    cruise = CruiseControl(1000, 30000)
    planner.adjust_altitude()
    simulator.simulate()
    cruise.control()
main()