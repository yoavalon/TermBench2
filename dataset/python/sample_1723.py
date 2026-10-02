class StateMachine:

    def __init__(self):
        self.state = 'idle'

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'data':
            self.state = 'transmitting'
        elif self.state == 'transmitting' and event == 'disconnect':
            self.state = 'disconnected'
        elif self.state == 'disconnected' and event == 'reset':
            self.state = 'idle'

    def handle_event(self, event):
        self.transition(event)
        return self.state

class EventGenerator:

    def __init__(self):
        self.events = ['connect', 'data', 'disconnect', 'reset']
        self.index = 0

    def next_event(self):
        event = self.events[self.index % len(self.events)]
        self.index += 1
        return event

class NetworkSystem:

    def __init__(self):
        self.state_machine = StateMachine()
        self.event_generator = EventGenerator()

    def run(self):
        while True:
            event = self.event_generator.next_event()
            state = self.state_machine.handle_event(event)
            print(f'Event: {event}, State: {state}')

def main():
    network_system = NetworkSystem()
    network_system.run()
main()