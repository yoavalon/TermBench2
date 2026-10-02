class SimulationEnvironment:

    def __init__(self, initial_state, temperature, pressure):
        self.state = initial_state
        self.temperature = temperature
        self.pressure = pressure

    def update_state(self, new_state):
        self.state = new_state

    def adjust_temperature(self, delta):
        self.temperature += delta

    def adjust_pressure(self, delta):
        self.pressure += delta

class StateAnalyzer:

    def analyze_state(self, state, temperature, pressure):
        if temperature > 100:
            return 'High temperature'
        elif pressure > 100:
            return 'High pressure'
        else:
            return 'Stable state'

class SimulationController:

    def __init__(self, environment, analyzer):
        self.environment = environment
        self.analyzer = analyzer

    def run_simulation(self):
        while True:
            analysis = self.analyzer.analyze_state(self.environment.state, self.environment.temperature, self.environment.pressure)
            if analysis == 'High temperature':
                self.environment.adjust_temperature(-10)
            elif analysis == 'High pressure':
                self.environment.adjust_pressure(-10)
            self.environment.update_state('New State')

def main():
    env = SimulationEnvironment('Initial State', 150, 110)
    analyzer = StateAnalyzer()
    controller = SimulationController(env, analyzer)
    controller.run_simulation()
main()