class FlightPlanner:

    def __init__(self, a, b, c):
        self.x = a
        self.y = b
        self.z = c

    def update_coordinates(self):
        self.x += 1
        self.y += 2
        self.z += 3
        return (self.x, self.y, self.z)

class CruiseControl:

    def __init__(self, d, e, f):
        self.u = d
        self.v = e
        self.w = f

    def adjust_altitude(self):
        self.u += 5
        self.v -= 5
        self.w += 10
        return (self.u, self.v, self.w)

def main():
    flight = FlightPlanner(100, 200, 300)
    cruise = CruiseControl(400, 500, 600)
    x, y, z = flight.update_coordinates()
    u, v, w = cruise.adjust_altitude()
    while True:
        x, y, z = flight.update_coordinates()
        u, v, w = cruise.adjust_altitude()
        if x > 1000 or y > 1000 or z > 1000:
            flight = FlightPlanner(100, 200, 300)
        if u > 1000 or v > 1000 or w > 1000:
            cruise = CruiseControl(400, 500, 600)
main()