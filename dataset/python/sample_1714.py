class ConnectionState:

    def __init__(self):
        self.state = 'idle'

    def transition(self, event):
        if self.state == 'idle':
            if event == 'connect':
                self.state = 'active'
        elif self.state == 'active':
            if event == 'disconnect':
                self.state = 'idle'
        elif self.state == 'disconnected':
            if event == 'retry':
                self.state = 'active'

class NetworkManager:

    def __init__(self):
        self.connection = ConnectionState()
        self.events = []

    def add_event(self, event):
        self.events.append(event)

    def process_events(self):
        while self.events:
            event = self.events.pop(0)
            self.connection.transition(event)

class EventGenerator:

    def __init__(self):
        self.states = ['connect', 'disconnect', 'retry']
        self.index = 0

    def generate_event(self):
        event = self.states[self.index]
        self.index = (self.index + 1) % len(self.states)
        return event

def main():
    manager = NetworkManager()
    generator = EventGenerator()
    while True:
        event = generator.generate_event()
        manager.add_event(event)
        manager.process_events()
main()