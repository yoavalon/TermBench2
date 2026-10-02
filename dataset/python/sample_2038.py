import math

class ThermodynamicState:

    def __init__(self, temp, pressure):
        self.temp = temp
        self.pressure = pressure

    def update_state(self, temp_change, pressure_change):
        self.temp += temp_change
        self.pressure += pressure_change

    def calculate_entropy(self):
        if self.temp <= 0:
            return math.nan
        return self.pressure / self.temp

class SimulationController:

    def __init__(self, initial_state, iterations):
        self.state = initial_state
        self.iterations = iterations
        self.data = []

    def run_simulation(self):
        for _ in range(self.iterations):
            self.state.update_state(0.1, -0.05)
            self.data.append(self.state.calculate_entropy())

    def get_results(self):
        return self.data

def analyze_data(data):
    total = 0
    count = 0
    for value in data:
        if not math.isnan(value):
            total += value
            count += 1
    return total / count if count > 0 else math.nan

def main():
    initial_state = ThermodynamicState(300, 100)
    controller = SimulationController(initial_state, 50)
    controller.run_simulation()
    results = controller.get_results()
    average_entropy = analyze_data(results)
    print(f'Average Entropy: {average_entropy}')
if __name__ == '__main__':
    main()