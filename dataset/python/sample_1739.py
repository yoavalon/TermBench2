class ThermodynamicSimulator:

    def __init__(self, state, temperature, pressure):
        self.state = state
        self.temperature = temperature
        self.pressure = pressure

    def update_state(self, new_state):
        self.state = new_state

    def adjust_temperature(self, delta):
        self.temperature += delta

    def adjust_pressure(self, delta):
        self.pressure += delta

class StateTransformer:

    def __init__(self, simulator):
        self.simulator = simulator

    def transform(self):
        while True:
            if self.simulator.temperature > 100:
                self.simulator.adjust_temperature(-10)
                self.simulator.update_state('Condensing')
            elif self.simulator.temperature < 0:
                self.simulator.adjust_temperature(10)
                self.simulator.update_state('Boiling')
            else:
                self.simulator.update_state('Stable')

class SimulationController:

    def __init__(self, simulator, transformer):
        self.simulator = simulator
        self.transformer = transformer

    def run(self):
        while True:
            self.transformer.transform()
            self.simulator.adjust_pressure(1)
            if self.simulator.pressure > 1000:
                self.simulator.adjust_pressure(-1000)

def main():
    initial_state = 'Liquid'
    initial_temperature = 50
    initial_pressure = 500
    simulator = ThermodynamicSimulator(initial_state, initial_temperature, initial_pressure)
    transformer = StateTransformer(simulator)
    controller = SimulationController(simulator, transformer)
    controller.run()
main()