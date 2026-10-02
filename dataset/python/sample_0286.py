class StateMachine:

    def __init__(self):
        self.state = 'idle'
        self.states = {'idle': self.idle, 'connected': self.connected, 'error': self.error}

    def transition(self, event):
        self.state = self.states[self.state](event)

    def idle(self, event):
        if event == 'connect':
            return 'connected'
        elif event == 'error':
            return 'error'
        return 'idle'

    def connected(self, event):
        if event == 'disconnect':
            return 'idle'
        elif event == 'error':
            return 'error'
        return 'connected'

    def error(self, event):
        if event == 'recover':
            return 'idle'
        return 'error'

def simulate_events(machine):
    events = ['connect', 'data', 'disconnect', 'connect', 'error', 'recover']
    for event in events:
        machine.transition(event)

def main():
    machine = StateMachine()
    simulate_events(machine)
if __name__ == '__main__':
    main()