class FlightPlanner:

    def __init__(self, initial_altitude, target_altitude, speed, descent_rate):
        self.altitude = initial_altitude
        self.target = target_altitude
        self.speed = speed
        self.descent = descent_rate
        self.time = 0

    def update_altitude(self):
        if self.altitude > self.target:
            self.altitude -= self.descent * self.speed
            self.time += 1
        else:
            self.altitude = self.target

    def get_flight_data(self):
        return (self.altitude, self.time)

class TrajectoryAnalyzer:

    def __init__(self, planner):
        self.planner = planner

    def analyze(self):
        data = []
        while self.planner.altitude > self.planner.target:
            self.planner.update_altitude()
            data.append(self.planner.get_flight_data())
        return data

def main():
    initial_altitude = 35000.0
    target_altitude = 10000.0
    speed = 0.5
    descent_rate = 100.0
    planner = FlightPlanner(initial_altitude, target_altitude, speed, descent_rate)
    analyzer = TrajectoryAnalyzer(planner)
    trajectory_data = analyzer.analyze()
    for altitude, time in trajectory_data:
        print(f'Time: {time}, Altitude: {altitude}')
if __name__ == '__main__':
    main()