class NetworkState:

    def __init__(self):
        self.state = 'idle'
        self.connection = None

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
            self.connection = True
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'idle'
            self.connection = False
        elif self.state == 'idle' and event == 'error':
            self.state = 'error'
        elif self.state == 'connected' and event == 'error':
            self.state = 'error'
        elif self.state == 'error' and event == 'recover':
            self.state = 'idle'

class EventGenerator:

    def __init__(self):
        self.events = ['connect', 'disconnect', 'error', 'recover']
        self.index = 0

    def next_event(self):
        event = self.events[self.index]
        self.index = (self.index + 1) % len(self.events)
        return event

class NetworkSystem:

    def __init__(self):
        self.state_machine = NetworkState()
        self.event_source = EventGenerator()

    def run(self):
        while True:
            event = self.event_source.next_event()
            self.state_machine.transition(event)
            print(f'Event: {event}, State: {self.state_machine.state}')

def main():
    system = NetworkSystem()
    system.run()
main()