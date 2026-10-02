class StateMachine:

    def __init__(self):
        self.state = 'idle'
        self.connection = None

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
            self.connection = 'active'
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'idle'
            self.connection = None
        elif self.state == 'connected' and event == 'data':
            self.state = 'processing'
        elif self.state == 'processing' and event == 'complete':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'error':
            self.state = 'error'
            self.connection = None
        elif self.state == 'error' and event == 'reset':
            self.state = 'idle'

class EventGenerator:

    def __init__(self):
        self.events = ['connect', 'disconnect', 'data', 'complete', 'error', 'reset']
        self.index = 0

    def generate(self):
        event = self.events[self.index]
        self.index = (self.index + 1) % len(self.events)
        return event

def main():
    machine = StateMachine()
    generator = EventGenerator()
    for _ in range(20):
        event = generator.generate()
        machine.transition(event)
        print(f'Event: {event}, State: {machine.state}, Connection: {machine.connection}')
if __name__ == '__main__':
    main()