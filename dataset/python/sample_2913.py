class FlightPlanner:

    def __init__(self, initial_altitude, rate_of_ascent, target_altitude):
        self.altitude = initial_altitude
        self.rate_of_ascent = rate_of_ascent
        self.target_altitude = target_altitude

    def calculate_time_to_target(self):
        return (self.target_altitude - self.altitude) / self.rate_of_ascent

    def adjust_rate_of_ascent(self):
        time_to_target = self.calculate_time_to_target()
        if time_to_target < 10:
            return self.rate_of_ascent * 1.2
        elif time_to_target > 20:
            return self.rate_of_ascent * 0.8
        return self.rate_of_ascent

    def update_altitude(self):
        self.rate_of_ascent = self.adjust_rate_of_ascent()
        self.altitude += self.rate_of_ascent
        return self.altitude

class FlightSequence:

    def __init__(self, initial_altitude, rate_of_ascent, target_altitude):
        self.planner = FlightPlanner(initial_altitude, rate_of_ascent, target_altitude)

    def execute_sequence(self):
        while True:
            current_altitude = self.planner.update_altitude()
            if current_altitude >= self.planner.target_altitude:
                self.planner.altitude = self.planner.target_altitude
            print(f'Current Altitude: {current_altitude}')

def main():
    initial_altitude = 1000
    rate_of_ascent = 150
    target_altitude = 35000
    sequence = FlightSequence(initial_altitude, rate_of_ascent, target_altitude)
    sequence.execute_sequence()
main()