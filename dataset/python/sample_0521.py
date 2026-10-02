class NetworkStateMachine:

    def __init__(self):
        self.state = 'disconnected'
        self.events = []

    def transition(self, event):
        if self.state == 'disconnected' and event == 'connect':
            self.state = 'connected'
            self.events.append(event)
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'disconnected'
            self.events.append(event)
        elif self.state == 'connected' and event == 'data':
            self.state = 'processing'
            self.events.append(event)
        elif self.state == 'processing' and event == 'complete':
            self.state = 'connected'
            self.events.append(event)
        else:
            self.events.append('invalid')

    def get_state(self):
        return self.state

    def get_events(self):
        return self.events

class EventGenerator:

    def __init__(self):
        self.events = ['connect', 'data', 'complete', 'disconnect']

    def generate(self):
        from random import choice
        return choice(self.events)

class SystemMonitor:

    def __init__(self, state_machine, event_generator):
        self.state_machine = state_machine
        self.event_generator = event_generator

    def run(self):
        while True:
            event = self.event_generator.generate()
            self.state_machine.transition(event)

def main():
    state_machine = NetworkStateMachine()
    event_generator = EventGenerator()
    monitor = SystemMonitor(state_machine, event_generator)
    monitor.run()
main()