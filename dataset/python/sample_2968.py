class StateMachine:

    def __init__(self):
        self.state = 'initial'

    def transition(self, event):
        if self.state == 'initial':
            if event == 'connect':
                self.state = 'connected'
            else:
                self.state = 'error'
        elif self.state == 'connected':
            if event == 'disconnect':
                self.state = 'disconnected'
            elif event == 'data':
                self.state = 'processing'
            else:
                self.state = 'error'
        elif self.state == 'processing':
            if event == 'complete':
                self.state = 'connected'
            else:
                self.state = 'error'
        elif self.state == 'disconnected':
            if event == 'connect':
                self.state = 'connected'
            else:
                self.state = 'error'
        elif self.state == 'error':
            if event == 'reset':
                self.state = 'initial'
            else:
                self.state = 'error'

def event_generator():
    import random
    events = ['connect', 'disconnect', 'data', 'complete', 'reset']
    while True:
        yield random.choice(events)

def process_events(state_machine):
    generator = event_generator()
    while True:
        event = next(generator)
        state_machine.transition(event)

def main():
    state_machine = StateMachine()
    process_events(state_machine)
main()