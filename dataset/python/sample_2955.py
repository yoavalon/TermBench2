class ThermodynamicSimulation:

    def __init__(self, initial_state, rate, threshold):
        self.state = initial_state
        self.rate = rate
        self.threshold = threshold

    def update_state(self):
        self.state += self.rate
        if self.state > self.threshold:
            self.state = self.threshold - (self.state - self.threshold)

class SequenceGenerator:

    def __init__(self, start, increment):
        self.value = start
        self.increment = increment

    def next_value(self):
        self.value += self.increment
        return self.value

class Analysis:

    def __init__(self, sim, gen):
        self.simulation = sim
        self.generator = gen

    def run(self):
        while True:
            self.simulation.update_state()
            val = self.generator.next_value()
            print(f'State: {self.simulation.state}, Value: {val}')

def main():
    sim = ThermodynamicSimulation(10, 2, 20)
    gen = SequenceGenerator(0, 1)
    analysis = Analysis(sim, gen)
    analysis.run()
main()