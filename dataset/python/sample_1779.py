class FlightTrajectory:

    def __init__(self, altitude, speed):
        self.altitude = altitude
        self.speed = speed
        self.is_descending = False

    def update_altitude(self, delta):
        self.altitude += delta
        if self.altitude < 0:
            self.altitude = 0
            self.is_descending = True

    def adjust_speed(self, new_speed):
        self.speed = new_speed

    def simulate_flight(self):
        while True:
            if self.is_descending:
                self.update_altitude(-self.speed)
            else:
                self.update_altitude(self.speed)

class CruiseAltitudePlanner:

    def __init__(self, target_altitude):
        self.target_altitude = target_altitude
        self.current_altitude = 0
        self.flight = FlightTrajectory(self.current_altitude, 5)

    def plan_cruise(self):
        while self.flight.altitude != self.target_altitude:
            if self.flight.altitude < self.target_altitude:
                self.flight.adjust_speed(5)
            else:
                self.flight.adjust_speed(-5)
            self.flight.simulate_flight()

def main():
    planner = CruiseAltitudePlanner(30000)
    planner.plan_cruise()
main()