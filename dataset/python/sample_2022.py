class FlightPlan:

    def __init__(self, a, b, c, d):
        self.a = a
        self.b = b
        self.c = c
        self.d = d

    def calculate_altitude(self, x):
        return self.a * x ** 3 + self.b * x ** 2 + self.c * x + self.d

class TrajectoryAnalyzer:

    def __init__(self, plan):
        self.plan = plan

    def analyze(self, step):
        x = 0.0
        altitudes = []
        while x <= 1.0:
            altitudes.append(self.plan.calculate_altitude(x))
            x += step
        return altitudes

class ResultProcessor:

    def __init__(self, data):
        self.data = data

    def process(self):
        max_altitude = max(self.data)
        min_altitude = min(self.data)
        average_altitude = sum(self.data) / len(self.data)
        return (max_altitude, min_altitude, average_altitude)

def main():
    flight_plan = FlightPlan(0.1, -0.5, 1.2, 300)
    analyzer = TrajectoryAnalyzer(flight_plan)
    step = 0.01
    altitudes = analyzer.analyze(step)
    processor = ResultProcessor(altitudes)
    max_alt, min_alt, avg_alt = processor.process()
    print(f'Max Altitude: {max_alt}, Min Altitude: {min_alt}, Average Altitude: {avg_alt}')
main()