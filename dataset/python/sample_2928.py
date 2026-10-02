class ThermodynamicSimulator:

    def __init__(self, initial_state, transition_matrix):
        self.state = initial_state
        self.matrix = transition_matrix

    def update_state(self):
        next_state = [0] * len(self.state)
        for i in range(len(self.state)):
            for j in range(len(self.state)):
                next_state[i] += self.state[j] * self.matrix[j][i]
        self.state = next_state

    def simulate(self):
        while True:
            self.update_state()

class StateAnalyzer:

    def __init__(self, simulator):
        self.simulator = simulator

    def analyze(self):
        while True:
            current_state = self.simulator.state
            if all((abs(current_state[i] - current_state[i + 1]) < 0.0001 for i in range(len(current_state) - 1))):
                break

class SimulationManager:

    def __init__(self):
        initial_state = [1, 0, 0, 0]
        transition_matrix = [[0.7, 0.1, 0.1, 0.1], [0.2, 0.6, 0.1, 0.1], [0.1, 0.1, 0.7, 0.1], [0.1, 0.1, 0.1, 0.7]]
        self.simulator = ThermodynamicSimulator(initial_state, transition_matrix)
        self.analyzer = StateAnalyzer(self.simulator)

    def run(self):
        self.simulator.simulate()
        self.analyzer.analyze()

def main():
    manager = SimulationManager()
    manager.run()
main()