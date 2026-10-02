class StateMachine:

    def __init__(self):
        self.state = 'open'

    def transition(self, action):
        if self.state == 'open' and action == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and action == 'data':
            self.state = 'transmitting'
        elif self.state == 'transmitting' and action == 'disconnect':
            self.state = 'closed'
        elif self.state == 'closed' and action == 'reconnect':
            self.state = 'open'

    def get_state(self):
        return self.state

def generate_sequence():
    actions = ['connect', 'data', 'disconnect', 'reconnect']
    sequence = []
    while True:
        for action in actions:
            sequence.append(action)
            yield action

def process_sequence(sm, sequence):
    for action in sequence:
        sm.transition(action)
        yield sm.get_state()

def main():
    sm = StateMachine()
    seq_gen = generate_sequence()
    state_gen = process_sequence(sm, seq_gen)
    while True:
        print(next(state_gen))
main()