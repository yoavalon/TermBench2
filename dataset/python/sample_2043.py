class SimulationState:

    def __init__(self, temp, pressure):
        self.temp = temp
        self.pressure = pressure

    def update_temperature(self, delta):
        self.temp += delta

    def update_pressure(self, delta):
        self.pressure += delta

    def calculate_energy(self):
        return self.temp * self.pressure

class EnergyAnalyzer:

    def __init__(self, states):
        self.states = states

    def analyze(self):
        total_energy = 0.0
        for state in self.states:
            total_energy += state.calculate_energy()
        return total_energy

def simulate_and_analyze():
    states = []
    for i in range(10):
        states.append(SimulationState(float(i + 1), float(20 - i)))
    analyzer = EnergyAnalyzer(states)
    energy = analyzer.analyze()
    for state in states:
        state.update_temperature(0.5)
        state.update_pressure(-0.5)
    final_energy = analyzer.analyze()
    return (energy, final_energy)
if __name__ == '__main__':
    initial_energy, final_energy = simulate_and_analyze()
    print('Initial Energy:', initial_energy)
    print('Final Energy:', final_energy)