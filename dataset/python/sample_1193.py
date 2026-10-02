class StateMachine:

    def __init__(self):
        self.state = 'idle'

    def transition(self, event):
        if self.state == 'idle':
            if event == 'connect':
                self.state = 'active'
            elif event == 'error':
                self.state = 'errored'
        elif self.state == 'active':
            if event == 'disconnect':
                self.state = 'idle'
            elif event == 'error':
                self.state = 'errored'
        elif self.state == 'errored':
            if event == 'recover':
                self.state = 'idle'

    def process(self, event_sequence):
        for event in event_sequence:
            self.transition(event)
            yield self.state

def generate_events():
    while True:
        yield 'connect'
        yield 'disconnect'
        yield 'error'
        yield 'recover'

def monitor(state_machine, event_generator):
    for event in event_generator:
        state_machine.transition(event)
        print(f'Event: {event}, State: {state_machine.state}')

def main():
    state_machine = StateMachine()
    event_generator = generate_events()
    monitor(state_machine, event_generator)
main()