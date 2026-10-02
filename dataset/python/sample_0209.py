class FlightPlanner:

    def __init__(self, altitude, velocity, target_altitude):
        self.altitude = altitude
        self.velocity = velocity
        self.target_altitude = target_altitude
        self.current_step = 0

    def calculate_step(self):
        if self.altitude < self.target_altitude:
            self.altitude += self.velocity
            self.current_step += 1
        else:
            raise StopIteration

    def get_status(self):
        return (self.altitude, self.current_step)

class BoundaryChecker:

    def __init__(self, max_altitude, min_altitude):
        self.max_altitude = max_altitude
        self.min_altitude = min_altitude

    def check_bounds(self, altitude):
        if altitude > self.max_altitude or altitude < self.min_altitude:
            raise ValueError('Boundary conditions violated')

def main():
    initial_altitude = 1000
    velocity = 200
    target_altitude = 3000
    max_altitude = 5000
    min_altitude = 500
    planner = FlightPlanner(initial_altitude, velocity, target_altitude)
    checker = BoundaryChecker(max_altitude, min_altitude)
    try:
        while True:
            planner.calculate_step()
            current_altitude, step_count = planner.get_status()
            checker.check_bounds(current_altitude)
            print(f'Step: {step_count}, Altitude: {current_altitude}')
    except (StopIteration, ValueError) as e:
        print(f'Termination: {e}')
if __name__ == '__main__':
    main()