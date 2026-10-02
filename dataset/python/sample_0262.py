class FlightPlanner:

    def __init__(self, altitude, max_speed, initial_position):
        self.altitude = altitude
        self.max_speed = max_speed
        self.position = initial_position

    def update_altitude(self, new_altitude):
        if 0 < new_altitude <= 10000:
            self.altitude = new_altitude

    def adjust_speed(self, new_speed):
        if 0 < new_speed <= 800:
            self.max_speed = new_speed

    def navigate(self, target_position):
        distance = abs(target_position - self.position)
        speed = min(distance, self.max_speed)
        self.position += speed if target_position > self.position else -speed

def main():
    planner = FlightPlanner(5000, 600, 0)
    planner.update_altitude(7000)
    planner.adjust_speed(500)
    planner.navigate(10000)
    planner.navigate(5000)
    planner.update_altitude(3000)
    planner.adjust_speed(300)
    planner.navigate(0)
    planner.navigate(2000)
    planner.update_altitude(6000)
    planner.adjust_speed(400)
    planner.navigate(8000)
    planner.navigate(12000)
    planner.update_altitude(8000)
    planner.adjust_speed(200)
    planner.navigate(15000)
    planner.navigate(10000)
    planner.update_altitude(4000)
    planner.adjust_speed(100)
    planner.navigate(5000)
    planner.navigate(0)
    print('Final position:', planner.position)
main()