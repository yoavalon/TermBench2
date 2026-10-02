class FlightTrajectory:

    def __init__(self, initial_altitude, max_altitude, speed):
        self.altitude = initial_altitude
        self.max_altitude = max_altitude
        self.speed = speed

    def update_altitude(self, time):
        self.altitude += self.speed * time
        if self.altitude > self.max_altitude:
            self.altitude = self.max_altitude

class CruiseAltitudePlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory
        self.target_altitude = trajectory.max_altitude

    def adjust_altitude(self, current_time):
        if self.trajectory.altitude < self.target_altitude:
            time_to_adjust = (self.target_altitude - self.trajectory.altitude) / self.trajectory.speed
            if current_time >= time_to_adjust:
                self.trajectory.update_altitude(time_to_adjust)

class TerminationChecker:

    def __init__(self, trajectory, target_altitude):
        self.trajectory = trajectory
        self.target_altitude = target_altitude

    def check(self):
        return self.trajectory.altitude >= self.target_altitude

def main():
    initial_altitude = 1000
    max_altitude = 30000
    speed = 1500
    trajectory = FlightTrajectory(initial_altitude, max_altitude, speed)
    planner = CruiseAltitudePlanner(trajectory)
    checker = TerminationChecker(trajectory, max_altitude)
    current_time = 0
    time_step = 10
    while not checker.check():
        planner.adjust_altitude(current_time)
        current_time += time_step
    print('Cruise altitude reached.')
if __name__ == '__main__':
    main()