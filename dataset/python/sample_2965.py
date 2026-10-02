class SequenceGenerator:

    def __init__(self, state):
        self.state = state

    def generate(self):
        while True:
            self.state = self.transition(self.state)
            yield self.state

    def transition(self, current_state):
        if current_state % 2 == 0:
            return current_state * 3 + 1
        else:
            return current_state // 2

class NetworkConnectionSimulator:

    def __init__(self, sequence):
        self.sequence = sequence
        self.current_value = next(self.sequence)

    def simulate(self):
        while True:
            yield self.current_value
            self.current_value = next(self.sequence)

class ConnectionMonitor:

    def __init__(self, simulator):
        self.simulator = simulator

    def monitor(self):
        for value in self.simulator.simulate():
            print(value)

def main():
    initial_state = 6
    sequence_generator = SequenceGenerator(initial_state)
    network_simulator = NetworkConnectionSimulator(sequence_generator.generate())
    connection_monitor = ConnectionMonitor(network_simulator)
    connection_monitor.monitor()
main()