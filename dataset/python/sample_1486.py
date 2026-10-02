class FlightTrajectory:

    def __init__(self, start_altitude, target_altitude, rate_of_climb):
        self.altitude = start_altitude
        self.target = target_altitude
        self.rate = rate_of_climb
        self.status = 'ascending'

    def update_altitude(self):
        if self.status == 'ascending':
            self.altitude += self.rate
            if self.altitude >= self.target:
                self.status = 'cruising'
                self.altitude = self.target
        return self.altitude

    def is_cruising(self):
        return self.status == 'cruising'

def plan_cruise_altitude(trajectory, max_iterations):
    iteration = 0
    while iteration < max_iterations and (not trajectory.is_cruising()):
        trajectory.update_altitude()
        iteration += 1
    return trajectory.altitude

def main():
    start = 1000
    target = 35000
    rate = 500
    max_iter = 1000
    trajectory = FlightTrajectory(start, target, rate)
    final_altitude = plan_cruise_altitude(trajectory, max_iter)
    print('Final Cruise Altitude:', final_altitude)
if __name__ == '__main__':
    main()