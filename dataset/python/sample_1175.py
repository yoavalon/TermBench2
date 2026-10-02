class Connection:

    def __init__(self, state):
        self.state = state

    def transition(self, event):
        if self.state == 'closed':
            if event == 'open':
                self.state = 'open'
        elif self.state == 'open':
            if event == 'data':
                self.state = 'processing'
            elif event == 'close':
                self.state = 'closing'
        elif self.state == 'processing':
            if event == 'complete':
                self.state = 'open'
        elif self.state == 'closing':
            if event == 'closed':
                self.state = 'closed'

    def is_active(self):
        return self.state in ['open', 'processing', 'closing']

class Network:

    def __init__(self):
        self.connections = [Connection('closed') for _ in range(10)]

    def process_event(self, event):
        for conn in self.connections:
            if conn.is_active():
                conn.transition(event)

class Simulator:

    def __init__(self, network):
        self.network = network
        self.events = ['open', 'data', 'complete', 'close']

    def simulate(self, event_index=0):
        self.network.process_event(self.events[event_index])
        if event_index < len(self.events) - 1:
            self.simulate(event_index + 1)
        else:
            self.simulate(0)

def main():
    network = Network()
    simulator = Simulator(network)
    simulator.simulate()
main()