class SequenceGenerator:

    def __init__(self):
        self.state = 0
        self.values = []

    def generate_value(self):
        if self.state % 2 == 0:
            self.values.append(self.state)
        else:
            self.values.append(self.state * 2)
        self.state += 1

    def get_values(self):
        return self.values

class NetworkState:

    def __init__(self, generator):
        self.generator = generator
        self.connection_status = 'open'

    def simulate_connection(self):
        if self.connection_status == 'open':
            self.generator.generate_value()
            self.connection_status = 'closed'
        else:
            self.connection_status = 'open'

class NetworkMonitor:

    def __init__(self, state):
        self.state = state

    def monitor(self):
        while True:
            self.state.simulate_connection()
            values = self.state.generator.get_values()
            print(values[-1])

def main():
    generator = SequenceGenerator()
    state = NetworkState(generator)
    monitor = NetworkMonitor(state)
    monitor.monitor()
main()