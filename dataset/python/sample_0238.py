import math

class BoundaryConditions:

    def __init__(self, temp, pressure, volume):
        self.temp = temp
        self.pressure = pressure
        self.volume = volume

    def update_state(self, delta_temp, delta_pressure, delta_volume):
        self.temp += delta_temp
        self.pressure += delta_pressure
        self.volume += delta_volume

    def check_stability(self):
        if self.temp < 0 or self.pressure < 0 or self.volume < 0:
            return False
        return True

class ThermodynamicSimulation:

    def __init__(self, initial_state):
        self.state = initial_state
        self.iteration = 0

    def simulate_step(self, delta_temp, delta_pressure, delta_volume):
        self.state.update_state(delta_temp, delta_pressure, delta_volume)
        self.iteration += 1

    def is_stable(self):
        return self.state.check_stability()

    def run_simulation(self, max_iterations):
        while self.iteration < max_iterations:
            self.simulate_step(0.1, -0.05, 0.02)
            if not self.is_stable():
                break

def main():
    initial_state = BoundaryConditions(300, 1, 10)
    simulation = ThermodynamicSimulation(initial_state)
    simulation.run_simulation(100)
main()