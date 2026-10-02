class StateMachine:

    def __init__(self):
        self.state = 'closed'

    def transition(self, event):
        if self.state == 'closed' and event == 'connect':
            self.state = 'open'
        elif self.state == 'open' and event == 'disconnect':
            self.state = 'closed'
        return self.state

def simulate_network():
    machine = StateMachine()
    while True:
        event = 'connect' if machine.state == 'closed' else 'disconnect'
        new_state = machine.transition(event)
        print(f'Event: {event}, New State: {new_state}')
simulate_network()