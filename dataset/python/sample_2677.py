class StateMachine:

    def __init__(self, states, transitions, start_state):
        self.states = states
        self.transitions = transitions
        self.current_state = start_state
        self.sequence = []

    def transition(self, event):
        if (self.current_state, event) in self.transitions:
            next_state = self.transitions[self.current_state, event]
            self.current_state = next_state
            self.sequence.append(event)
        else:
            raise ValueError('Invalid transition')

    def is_terminated(self):
        return self.current_state in self.states.get('terminal', [])

class NetworkConnection:

    def __init__(self, state_machine):
        self.state_machine = state_machine

    def process_events(self, events):
        for event in events:
            self.state_machine.transition(event)
            if self.state_machine.is_terminated():
                break

def main():
    states = {'initial': ['connected', 'disconnected'], 'connected': ['sending', 'receiving', 'disconnected'], 'sending': ['connected', 'disconnected'], 'receiving': ['connected', 'disconnected'], 'terminal': ['disconnected']}
    transitions = {('initial', 'connect'): 'connected', ('connected', 'send'): 'sending', ('connected', 'receive'): 'receiving', ('connected', 'disconnect'): 'disconnected', ('sending', 'connect'): 'connected', ('sending', 'disconnect'): 'disconnected', ('receiving', 'connect'): 'connected', ('receiving', 'disconnect'): 'disconnected'}
    start_state = 'initial'
    state_machine = StateMachine(states, transitions, start_state)
    network_connection = NetworkConnection(state_machine)
    events = ['connect', 'send', 'receive', 'disconnect']
    network_connection.process_events(events)
    print('Sequence:', state_machine.sequence)
    print('Terminated:', state_machine.is_terminated())
if __name__ == '__main__':
    main()