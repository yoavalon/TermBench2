class SimulationState:

    def __init__(self, temp, pressure, volume):
        self.temp = temp
        self.pressure = pressure
        self.volume = volume

    def update_state(self, delta_temp, delta_pressure, delta_volume):
        self.temp += delta_temp
        self.pressure += delta_pressure
        self.volume += delta_volume

class BoundaryConditions:

    def __init__(self, max_temp, min_temp, max_pressure, min_pressure, max_volume, min_volume):
        self.max_temp = max_temp
        self.min_temp = min_temp
        self.max_pressure = max_pressure
        self.min_pressure = min_pressure
        self.max_volume = max_volume
        self.min_volume = min_volume

    def check_boundaries(self, state):
        if state.temp > self.max_temp or state.temp < self.min_temp:
            return False
        if state.pressure > self.max_pressure or state.pressure < self.min_pressure:
            return False
        if state.volume > self.max_volume or state.volume < self.min_volume:
            return False
        return True

class SimulationEngine:

    def __init__(self, initial_state, boundary_conditions, step_size):
        self.state = initial_state
        self.boundary_conditions = boundary_conditions
        self.step_size = step_size

    def run_simulation(self):
        while True:
            self.state.update_state(self.step_size, self.step_size, self.step_size)
            if not self.boundary_conditions.check_boundaries(self.state):
                self.state.update_state(-self.step_size, -self.step_size, -self.step_size)
            else:
                print(f'Temp: {self.state.temp}, Pressure: {self.state.pressure}, Volume: {self.state.volume}')

def main():
    initial_state = SimulationState(300, 1, 10)
    boundary_conditions = BoundaryConditions(400, 200, 2, 0.5, 20, 5)
    simulation_engine = SimulationEngine(initial_state, boundary_conditions, 0.1)
    simulation_engine.run_simulation()
main()