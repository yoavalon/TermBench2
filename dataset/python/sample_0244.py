class NetworkState:

    def __init__(self):
        self.state = 'init'

    def transition(self, event):
        if self.state == 'init' and event == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'disconnected'
        elif self.state == 'disconnected' and event == 'reconnect':
            self.state = 'connected'

class EventProcessor:

    def __init__(self, state_machine):
        self.state_machine = state_machine
        self.events = []

    def add_event(self, event):
        self.events.append(event)

    def process_events(self):
        for event in self.events:
            self.state_machine.transition(event)
        self.events.clear()

def main():
    state_machine = NetworkState()
    processor = EventProcessor(state_machine)
    processor.add_event('connect')
    processor.process_events()
    processor.add_event('disconnect')
    processor.process_events()
    processor.add_event('reconnect')
    processor.process_events()
    print(state_machine.state)
if __name__ == '__main__':
    main()