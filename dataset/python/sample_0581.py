class ThermodynamicState:

    def __init__(self, temperature, pressure):
        self.temperature = temperature
        self.pressure = pressure

    def update_state(self, delta_temp, delta_press):
        self.temperature += delta_temp
        self.pressure += delta_press

class BoundaryConditions:

    def __init__(self, max_temp, min_temp, max_press, min_press):
        self.max_temp = max_temp
        self.min_temp = min_temp
        self.max_press = max_press
        self.min_press = min_press

    def check_boundaries(self, state):
        if state.temperature > self.max_temp:
            state.temperature = self.max_temp
        elif state.temperature < self.min_temp:
            state.temperature = self.min_temp
        if state.pressure > self.max_press:
            state.pressure = self.max_press
        elif state.pressure < self.min_press:
            state.pressure = self.min_press

def simulate(state, conditions):
    while True:
        delta_temp = 1.5
        delta_press = -0.5
        state.update_state(delta_temp, delta_press)
        conditions.check_boundaries(state)

def main():
    initial_temp = 300
    initial_press = 1.0
    max_temp = 500
    min_temp = 200
    max_press = 2.0
    min_press = 0.5
    state = ThermodynamicState(initial_temp, initial_press)
    conditions = BoundaryConditions(max_temp, min_temp, max_press, min_press)
    simulate(state, conditions)
main()