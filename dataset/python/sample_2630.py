class SequenceGenerator:

    def __init__(self, start, step, count):
        self.start = start
        self.step = step
        self.count = count
        self.current = start
        self.index = 0

    def next(self):
        if self.index < self.count:
            value = self.current
            self.current += self.step
            self.index += 1
            return value
        else:
            return None

class FlightTrajectory:

    def __init__(self, initial_altitude, rate_of_climb, cruise_altitude, descent_rate, sequence):
        self.initial_altitude = initial_altitude
        self.rate_of_climb = rate_of_climb
        self.cruise_altitude = cruise_altitude
        self.descent_rate = descent_rate
        self.sequence = sequence
        self.current_altitude = initial_altitude

    def plan_cruise(self):
        climb_sequence = SequenceGenerator(self.initial_altitude, self.rate_of_climb, 100)
        while True:
            next_altitude = climb_sequence.next()
            if next_altitude is None or next_altitude >= self.cruise_altitude:
                break
            self.current_altitude = next_altitude
        if self.current_altitude < self.cruise_altitude:
            self.current_altitude = self.cruise_altitude
        descent_sequence = SequenceGenerator(self.current_altitude, -self.descent_rate, 100)
        while True:
            next_altitude = descent_sequence.next()
            if next_altitude is None or next_altitude <= 0:
                break
            self.current_altitude = next_altitude
        if self.current_altitude > 0:
            self.current_altitude = 0

def main():
    sequence = SequenceGenerator(0, 100, 200)
    trajectory = FlightTrajectory(1000, 500, 30000, 200, sequence)
    trajectory.plan_cruise()
    print(f'Final Altitude: {trajectory.current_altitude}')
main()