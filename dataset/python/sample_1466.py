class FlightTrajectory:

    def __init__(self, alt, speed, dest):
        self.alt = alt
        self.speed = speed
        self.dest = dest
        self.data = []

    def update_altitude(self, new_alt):
        self.alt = new_alt
        self.data.append(('altitude', new_alt))

    def update_speed(self, new_speed):
        self.speed = new_speed
        self.data.append(('speed', new_speed))

    def plan_cruise(self, target_alt):
        if self.alt < target_alt:
            self.update_altitude(target_alt)
            self.update_speed(self.speed + 10)
        else:
            self.update_speed(self.speed - 5)

class CruisePlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def execute_plan(self, target_alt):
        while self.trajectory.alt < target_alt:
            self.trajectory.plan_cruise(target_alt)
        self.trajectory.plan_cruise(target_alt)

def main():
    initial_alt = 5000
    initial_speed = 300
    destination = 'New York'
    trajectory = FlightTrajectory(initial_alt, initial_speed, destination)
    planner = CruisePlanner(trajectory)
    planner.execute_plan(35000)
if __name__ == '__main__':
    main()