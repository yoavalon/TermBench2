class ConnectionState:

    def __init__(self):
        self.state = 'idle'
        self.connection_id = 0

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'established'
            self.connection_id += 1
        elif self.state == 'established' and event == 'disconnect':
            self.state = 'idle'
        elif self.state == 'established' and event == 'data':
            self.state = 'transmitting'
        elif self.state == 'transmitting' and event == 'complete':
            self.state = 'established'
        return self.state

class NetworkSimulator:

    def __init__(self):
        self.connection = ConnectionState()

    def process_event(self, event):
        new_state = self.connection.transition(event)
        return new_state

class EventGenerator:

    def __init__(self):
        self.events = ['connect', 'data', 'complete', 'disconnect']
        self.index = 0

    def generate(self):
        event = self.events[self.index % len(self.events)]
        self.index += 1
        return event

def main():
    simulator = NetworkSimulator()
    generator = EventGenerator()
    while True:
        event = generator.generate()
        new_state = simulator.process_event(event)
        print(f'Event: {event}, New State: {new_state}')
main()