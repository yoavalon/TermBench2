class FlightTrajectory:

    def __init__(self, initial_altitude, max_altitude, speed):
        self.altitude = initial_altitude
        self.max_altitude = max_altitude
        self.speed = speed
        self.climbing = True

    def adjust_altitude(self):
        if self.climbing:
            self.altitude += self.speed
            if self.altitude >= self.max_altitude:
                self.climbing = False
        else:
            self.altitude -= self.speed
            if self.altitude <= 0:
                self.climbing = True

    def simulate_flight(self):
        while True:
            self.adjust_altitude()

class CruiseAltitudePlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def plan_cruise(self):
        while True:
            if self.trajectory.climbing:
                print(f'Climbing to {self.trajectory.altitude} meters')
            else:
                print(f'Descending to {self.trajectory.altitude} meters')

def main():
    trajectory = FlightTrajectory(initial_altitude=1000, max_altitude=10000, speed=100)
    planner = CruiseAltitudePlanner(trajectory)
    planner.plan_cruise()
main()