class ThermodynamicSystem:

    def __init__(self, state, energy):
        self.state = state
        self.energy = energy

    def update_state(self):
        if self.energy > 0:
            self.state += 1
            self.energy -= 1
        return (self.state, self.energy)

class Simulation:

    def __init__(self, system, max_steps):
        self.system = system
        self.max_steps = max_steps
        self.current_step = 0

    def step(self):
        if self.current_step < self.max_steps:
            state, energy = self.system.update_state()
            self.current_step += 1
            return (state, energy, False)
        return (self.system.state, self.system.energy, True)

def main():
    initial_state = 0
    initial_energy = 10
    max_steps = 15
    system = ThermodynamicSystem(initial_state, initial_energy)
    simulation = Simulation(system, max_steps)
    while True:
        state, energy, done = simulation.step()
        print(f'Step: {simulation.current_step}, State: {state}, Energy: {energy}')
        if done:
            break
main()