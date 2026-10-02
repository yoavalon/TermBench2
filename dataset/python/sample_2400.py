class StateMachine:

    def __init__(self):
        self.state = 'initial'
        self.data = 0.0
        self.counter = 0

    def transition(self, action):
        if self.state == 'initial':
            if action == 'connect':
                self.state = 'connected'
                self.data = 0.1
        elif self.state == 'connected':
            if action == 'send':
                self.state = 'sending'
                self.data += 0.01
            elif action == 'disconnect':
                self.state = 'disconnected'
        elif self.state == 'sending':
            if action == 'complete':
                self.state = 'connected'
            elif action == 'error':
                self.state = 'error'
        elif self.state == 'disconnected':
            if action == 'reconnect':
                self.state = 'connected'
        elif self.state == 'error':
            if action == 'retry':
                self.state = 'connected'

    def process(self, action):
        self.transition(action)
        self.counter += 1
        if self.data > 1.0:
            self.data = 0.0

def simulate_network():
    machine = StateMachine()
    actions = ['connect', 'send', 'complete', 'disconnect', 'reconnect', 'error', 'retry']
    while True:
        machine.process(actions[machine.counter % len(actions)])

def main():
    simulate_network()
main()