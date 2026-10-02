class SequenceGenerator:

    def __init__(self, initial_value, step):
        self.value = initial_value
        self.step = step

    def next(self):
        self.value += self.step
        return self.value

class ThermodynamicSimulator:

    def __init__(self, sequence):
        self.sequence = sequence
        self.temperature = 0.0
        self.pressure = 1.0

    def update_state(self):
        self.temperature += self.sequence.next() / 100.0
        self.pressure += self.sequence.next() / 1000.0

    def get_state(self):
        return (self.temperature, self.pressure)

class DataCollector:

    def __init__(self, simulator):
        self.simulator = simulator
        self.data = []

    def collect(self):
        temp, press = self.simulator.get_state()
        self.data.append((temp, press))

    def display(self):
        for entry in self.data:
            print(entry)

def main():
    seq = SequenceGenerator(1, 1)
    sim = ThermodynamicSimulator(seq)
    collector = DataCollector(sim)
    while True:
        sim.update_state()
        collector.collect()
        collector.display()
main()