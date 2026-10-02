class NetworkStateMachine:

    def __init__(self, state):
        self.state = state

    def transition(self):
        if self.state == 'CONNECTING':
            self.state = 'ESTABLISHED'
        elif self.state == 'ESTABLISHED':
            self.state = 'DISCONNECTING'
        elif self.state == 'DISCONNECTING':
            self.state = 'CONNECTING'
        return self

def recursive_process(state_machine):
    print(state_machine.state)
    state_machine.transition()
    recursive_process(state_machine)

def main():
    initial_state = 'CONNECTING'
    state_machine = NetworkStateMachine(initial_state)
    recursive_process(state_machine)
main()