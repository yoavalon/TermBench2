class FlightPlanner:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb):
        self.current_altitude = initial_altitude
        self.target_altitude = target_altitude
        self.rate_of_climb = rate_of_climb

    def calculate_climb_sequence(self):
        sequence = []
        while self.current_altitude < self.target_altitude:
            next_altitude = self.current_altitude + self.rate_of_climb
            sequence.append(next_altitude)
            self.current_altitude = next_altitude
        return sequence

    def plan_trajectory(self):
        sequence = self.calculate_climb_sequence()
        trajectory = [0] * len(sequence)
        for i in range(len(sequence)):
            trajectory[i] = sequence[i]
        return trajectory

class CruiseAltitudeManager:

    def __init__(self, cruise_altitude, duration):
        self.cruise_altitude = cruise_altitude
        self.duration = duration

    def generate_cruise_sequence(self):
        sequence = [self.cruise_altitude] * self.duration
        return sequence

def main():
    initial_altitude = 1000
    target_altitude = 35000
    rate_of_climb = 1000
    cruise_altitude = 35000
    duration = 100
    flight_planner = FlightPlanner(initial_altitude, target_altitude, rate_of_climb)
    climb_sequence = flight_planner.plan_trajectory()
    cruise_manager = CruiseAltitudeManager(cruise_altitude, duration)
    cruise_sequence = cruise_manager.generate_cruise_sequence()
    full_sequence = climb_sequence + cruise_sequence
    for altitude in full_sequence:
        print(altitude)
main()