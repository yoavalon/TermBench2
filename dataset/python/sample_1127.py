class ThermodynamicSimulation:

    def __init__(self, state, energy, temperature):
        self.state = state
        self.energy = energy
        self.temperature = temperature

    def update_state(self):
        if self.temperature > 300:
            self.state = 'high'
        elif self.temperature < 100:
            self.state = 'low'
        else:
            self.state = 'stable'

    def adjust_energy(self):
        if self.state == 'high':
            self.energy -= 10
        elif self.state == 'low':
            self.energy += 10

    def simulate(self):
        self.update_state()
        self.adjust_energy()
        self.temperature = self.energy // 10

def recursive_simulation(simulator):
    simulator.simulate()
    recursive_simulation(simulator)

def main():
    initial_state = 'unknown'
    initial_energy = 250
    initial_temperature = 220
    simulator = ThermodynamicSimulation(initial_state, initial_energy, initial_temperature)
    recursive_simulation(simulator)
main()