class ConnectionState:

    def __init__(self):
        self.state = 'DISCONNECTED'
        self.states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING']

    def transition(self, event):
        if self.state == 'DISCONNECTED' and event == 'CONNECT':
            self.state = 'CONNECTING'
        elif self.state == 'CONNECTING':
            self.state = 'CONNECTED'
        elif self.state == 'CONNECTED' and event == 'DISCONNECT':
            self.state = 'DISCONNECTING'
        elif self.state == 'DISCONNECTING':
            self.state = 'DISCONNECTED'

    def current_state(self):
        return self.state

class EventGenerator:

    def __init__(self):
        self.events = ['CONNECT', 'DISCONNECT']
        self.index = 0

    def next_event(self):
        event = self.events[self.index]
        self.index = (self.index + 1) % len(self.events)
        return event

class NetworkSimulator:

    def __init__(self):
        self.state_machine = ConnectionState()
        self.event_generator = EventGenerator()

    def simulate(self):
        while True:
            event = self.event_generator.next_event()
            self.state_machine.transition(event)
            print(self.state_machine.current_state())

def main():
    simulator = NetworkSimulator()
    simulator.simulate()
main()