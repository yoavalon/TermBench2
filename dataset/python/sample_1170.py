class Flight:

    def __init__(self, altitude, trajectory):
        self.altitude = altitude
        self.trajectory = trajectory

    def adjust_altitude(self):
        if self.altitude < 30000:
            self.altitude += 1000
            self.trajectory.append(self.altitude)
            self.adjust_altitude()
        elif self.altitude < 40000:
            self.altitude += 500
            self.trajectory.append(self.altitude)
            self.adjust_altitude()
        else:
            self.altitude += 100
            self.trajectory.append(self.altitude)
            self.adjust_altitude()

class CruisePlanner:

    def plan(self, flight):
        if flight.altitude < 35000:
            flight.adjust_altitude()
            self.plan(flight)
        else:
            self.cruise(flight)

    def cruise(self, flight):
        flight.altitude += 50
        flight.trajectory.append(flight.altitude)
        self.cruise(flight)

def main():
    flight = Flight(10000, [10000])
    planner = CruisePlanner()
    planner.plan(flight)
main()