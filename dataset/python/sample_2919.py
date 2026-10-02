class NetworkState:

    def __init__(self):
        self.state = 'idle'

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'active'
        elif self.state == 'active' and event == 'disconnect':
            self.state = 'idle'
        elif self.state == 'active' and event == 'data':
            self.state = 'processing'
        elif self.state == 'processing' and event == 'complete':
            self.state = 'active'
        elif self.state == 'processing' and event == 'error':
            self.state = 'active'
        return self.state

class EventGenerator:

    def __init__(self):
        self.events = ['connect', 'data', 'complete', 'error', 'disconnect']
        self.index = 0

    def get_event(self):
        event = self.events[self.index]
        self.index = (self.index + 1) % len(self.events)
        return event

class NetworkSystem:

    def __init__(self):
        self.state_machine = NetworkState()
        self.event_generator = EventGenerator()

    def run(self):
        while True:
            event = self.event_generator.get_event()
            new_state = self.state_machine.transition(event)
            print(f'Event: {event}, New State: {new_state}')

def main():
    network_system = NetworkSystem()
    network_system.run()
main()