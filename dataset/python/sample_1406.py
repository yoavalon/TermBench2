class FlightPlanner:

    def __init__(self, initial_altitude, target_altitude, altitude_step, descent_rate):
        self.current_altitude = initial_altitude
        self.target_altitude = target_altitude
        self.altitude_step = altitude_step
        self.descent_rate = descent_rate

    def adjust_altitude(self):
        if self.current_altitude > self.target_altitude:
            self.current_altitude -= self.altitude_step
            if self.current_altitude < self.target_altitude:
                self.current_altitude = self.target_altitude
        else:
            self.current_altitude += self.altitude_step
            if self.current_altitude > self.target_altitude:
                self.current_altitude = self.target_altitude

    def simulate_flight(self):
        while self.current_altitude != self.target_altitude:
            self.adjust_altitude()
        return self.current_altitude

class TrajectoryAnalyzer:

    def __init__(self, initial_position, target_position, position_step, direction):
        self.current_position = initial_position
        self.target_position = target_position
        self.position_step = position_step
        self.direction = direction

    def update_position(self):
        if self.current_position < self.target_position:
            self.current_position += self.position_step
        elif self.current_position > self.target_position:
            self.current_position -= self.position_step

    def analyze_trajectory(self):
        while self.current_position != self.target_position:
            self.update_position()
        return self.current_position

def main():
    altitude_planner = FlightPlanner(initial_altitude=30000, target_altitude=35000, altitude_step=1000, descent_rate=500)
    trajectory_analyzer = TrajectoryAnalyzer(initial_position=0, target_position=1000, position_step=100, direction=1)
    final_altitude = altitude_planner.simulate_flight()
    final_position = trajectory_analyzer.analyze_trajectory()
    print(f'Final Altitude: {final_altitude}')
    print(f'Final Position: {final_position}')
main()