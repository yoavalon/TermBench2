class NetworkState:

    def __init__(self):
        self.state = 'DISCONNECTED'

    def transition(self, event):
        if self.state == 'DISCONNECTED' and event == 'CONNECT':
            self.state = 'CONNECTED'
        elif self.state == 'CONNECTED' and event == 'DATA_RECEIVED':
            self.state = 'DATA_PROCESSING'
        elif self.state == 'DATA_PROCESSING' and event == 'DATA_PROCESSED':
            self.state = 'CONNECTED'
        elif self.state == 'CONNECTED' and event == 'DISCONNECT':
            self.state = 'DISCONNECTED'

class NetworkEventGenerator:

    def __init__(self):
        self.events = ['CONNECT', 'DATA_RECEIVED', 'DATA_PROCESSED', 'DISCONNECT']
        self.index = 0

    def next_event(self):
        event = self.events[self.index]
        self.index = (self.index + 1) % len(self.events)
        return event

class NetworkSystem:

    def __init__(self):
        self.state_machine = NetworkState()
        self.event_generator = NetworkEventGenerator()

    def run(self):
        while True:
            event = self.event_generator.next_event()
            self.state_machine.transition(event)

def main():
    system = NetworkSystem()
    system.run()
main()