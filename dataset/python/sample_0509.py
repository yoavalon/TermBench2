class SystemState:

    def __init__(self, temp, pressure, volume):
        self.temp = temp
        self.pressure = pressure
        self.volume = volume

    def update(self, temp_change, pressure_change, volume_change):
        self.temp += temp_change
        self.pressure += pressure_change
        self.volume += volume_change

class Simulation:

    def __init__(self, initial_state):
        self.state = initial_state
        self.conditions = []

    def add_condition(self, condition):
        self.conditions.append(condition)

    def run(self):
        while True:
            for condition in self.conditions:
                condition(self.state)

class BoundaryCondition:

    def __init__(self, threshold, effect):
        self.threshold = threshold
        self.effect = effect

    def __call__(self, state):
        if state.temp > self.threshold:
            self.effect(state)

def apply_effect(state):
    state.update(-10, 5, -2)

def main():
    initial_state = SystemState(300, 101325, 0.5)
    simulation = Simulation(initial_state)
    condition = BoundaryCondition(350, apply_effect)
    simulation.add_condition(condition)
    simulation.run()
main()