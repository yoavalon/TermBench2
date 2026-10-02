class NetworkState:

    def __init__(self):
        self.state = 'idle'
        self.sequence = []

    def transition(self, action):
        if self.state == 'idle' and action == 'connect':
            self.state = 'active'
            self.sequence.append(1)
        elif self.state == 'active' and action == 'data':
            self.sequence.append(2)
        elif self.state == 'active' and action == 'disconnect':
            self.state = 'idle'
            self.sequence.append(3)
        elif self.state == 'idle' and action == 'reset':
            self.sequence.append(4)
        else:
            self.sequence.append(0)

    def get_sequence(self):
        return self.sequence

def generate_actions():
    actions = ['connect', 'data', 'disconnect', 'reset']
    while True:
        for action in actions:
            yield action

def main():
    network = NetworkState()
    actions = generate_actions()
    for action in actions:
        network.transition(action)
        print(network.get_sequence())
main()