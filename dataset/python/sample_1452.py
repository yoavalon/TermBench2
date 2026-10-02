import numpy as np

class FlightTrajectory:

    def __init__(self, initial_altitude, target_altitude, max_altitude, rate_of_climb):
        self.altitude = initial_altitude
        self.target_altitude = target_altitude
        self.max_altitude = max_altitude
        self.rate_of_climb = rate_of_climb
        self.time = 0

    def update_altitude(self):
        if self.altitude < self.target_altitude:
            self.altitude += self.rate_of_climb
            if self.altitude > self.max_altitude:
                self.altitude = self.max_altitude
        self.time += 1

    def is_complete(self):
        return self.altitude >= self.target_altitude

class CruiseAltitudePlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def plan_cruise(self):
        while not self.trajectory.is_complete():
            self.trajectory.update_altitude()
        return (self.trajectory.altitude, self.trajectory.time)

def main():
    initial_altitude = 1000
    target_altitude = 35000
    max_altitude = 40000
    rate_of_climb = 1500
    trajectory = FlightTrajectory(initial_altitude, target_altitude, max_altitude, rate_of_climb)
    planner = CruiseAltitudePlanner(trajectory)
    final_altitude, climb_time = planner.plan_cruise()
    print(f'Final Altitude: {final_altitude}, Climb Time: {climb_time}')
if __name__ == '__main__':
    main()