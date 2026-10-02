class StateSimulator:

    def __init__(self, initial_temp):
        self.temp = initial_temp
        self.energy = 0

    def update_energy(self, delta):
        self.energy += delta

    def adjust_temperature(self, factor):
        self.temp *= factor

class MutationEngine:

    def __init__(self, base_state):
        self.state = base_state
        self.mutations = []

    def apply_mutation(self, mutation):
        self.mutations.append(mutation)
        mutation(self.state)

    def get_current_energy(self):
        return self.state.energy

class SimulationLoop:

    def __init__(self, engine):
        self.engine = engine
        self.iteration = 0

    def run(self):
        while True:
            self.iteration += 1
            self.apply_random_mutation()
            self.adjust_temperature()

    def apply_random_mutation(self):
        mutation = self.random_mutation()
        self.engine.apply_mutation(mutation)

    def adjust_temperature(self):
        factor = 1.005 if self.iteration % 10 == 0 else 0.995
        self.engine.state.adjust_temperature(factor)

    def random_mutation(self):
        import random
        return lambda state: state.update_energy(random.randint(-10, 10))

def main():
    initial_temp = 300
    state = StateSimulator(initial_temp)
    engine = MutationEngine(state)
    simulation = SimulationLoop(engine)
    simulation.run()
main()