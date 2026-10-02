class NetworkState:

    def __init__(self):
        self.state = 'idle'

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'idle'
        elif self.state == 'idle' and event == 'error':
            self.state = 'error'
        elif self.state == 'connected' and event == 'error':
            self.state = 'error'
        elif self.state == 'error' and event == 'recover':
            self.state = 'idle'

class EventGenerator:

    def __init__(self):
        self.event_sequence = ['connect', 'data', 'disconnect', 'connect', 'data', 'error', 'recover']

    def next_event(self):
        return self.event_sequence.pop(0) if self.event_sequence else None

class NetworkSystem:

    def __init__(self):
        self.state_machine = NetworkState()
        self.event_generator = EventGenerator()

    def process_events(self):
        while True:
            event = self.event_generator.next_event()
            if event:
                self.state_machine.transition(event)
                if self.state_machine.state == 'error':
                    self.handle_error()

    def handle_error(self):
        print('Error state reached, attempting recovery...')
        self.state_machine.transition('recover')

def main():
    network_system = NetworkSystem()
    network_system.process_events()
main()