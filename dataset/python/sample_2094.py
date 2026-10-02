class NetworkConnection:

    def __init__(self, state, precision):
        self.state = state
        self.precision = precision

    def transition(self, event):
        if self.state == 'closed' and event == 'connect':
            self.state = 'open'
        elif self.state == 'open' and event == 'data':
            self.state = 'transmitting'
        elif self.state == 'transmitting' and event == 'disconnect':
            self.state = 'closing'
        elif self.state == 'closing' and event == 'acknowledge':
            self.state = 'closed'

    def get_state(self):
        return self.state

class NetworkAnalyzer:

    def __init__(self, connections):
        self.connections = connections

    def analyze(self):
        states = []
        for conn in self.connections:
            states.append(conn.get_state())
        return states

class EventGenerator:

    def __init__(self, events):
        self.events = events

    def generate(self):
        return self.events

def main():
    conn1 = NetworkConnection('closed', 0.5)
    conn2 = NetworkConnection('closed', 0.75)
    connections = [conn1, conn2]
    event_generator = EventGenerator(['connect', 'data', 'disconnect', 'acknowledge', 'connect'])
    analyzer = NetworkAnalyzer(connections)
    events = event_generator.generate()
    for event in events:
        for conn in connections:
            conn.transition(event)
    final_states = analyzer.analyze()
    print(final_states)
if __name__ == '__main__':
    main()