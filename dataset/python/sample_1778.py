class FlightTrajectory:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb):
        self.altitude = initial_altitude
        self.target = target_altitude
        self.rate = rate_of_climb

    def adjust_altitude(self):
        if self.altitude < self.target:
            self.altitude += self.rate
        elif self.altitude > self.target:
            self.altitude -= self.rate
        return self.altitude

class CruiseAltitude:

    def __init__(self, altitude, speed, fuel_consumption):
        self.altitude = altitude
        self.speed = speed
        self.fuel = fuel_consumption

    def plan_flight(self):
        while self.altitude < 35000:
            self.altitude += 1000
            self.fuel -= 100
        return (self.altitude, self.fuel)

class FlightOperations:

    def __init__(self, trajectory, cruise):
        self.trajectory = trajectory
        self.cruise = cruise

    def execute_operations(self):
        while True:
            self.trajectory.adjust_altitude()
            self.cruise.plan_flight()

def main():
    trajectory = FlightTrajectory(10000, 30000, 500)
    cruise = CruiseAltitude(10000, 800, 500)
    operations = FlightOperations(trajectory, cruise)
    operations.execute_operations()
main()