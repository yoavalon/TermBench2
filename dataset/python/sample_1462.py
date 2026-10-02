class FlightData:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb):
        self.altitude = initial_altitude
        self.target_altitude = target_altitude
        self.rate_of_climb = rate_of_climb

    def update_altitude(self):
        if self.altitude < self.target_altitude:
            self.altitude += self.rate_of_climb
        else:
            self.altitude = self.target_altitude

class TrajectoryPlanner:

    def __init__(self, data):
        self.data = data

    def plan_trajectory(self):
        while self.data.altitude < self.data.target_altitude:
            self.data.update_altitude()
            self.adjust_cruise_altitude()

    def adjust_cruise_altitude(self):
        if self.data.altitude > 30000:
            self.data.rate_of_climb = 500
        elif self.data.altitude > 20000:
            self.data.rate_of_climb = 1000
        else:
            self.data.rate_of_climb = 1500

def main():
    initial_altitude = 10000
    target_altitude = 40000
    rate_of_climb = 2000
    flight_data = FlightData(initial_altitude, target_altitude, rate_of_climb)
    trajectory_planner = TrajectoryPlanner(flight_data)
    trajectory_planner.plan_trajectory()
    print('Final Altitude:', flight_data.altitude)
main()