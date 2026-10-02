class StateMachine:

    def __init__(self):
        self.state = 'idle'
        self.sequence = [1, 2, 3, 4, 5]
        self.index = 0

    def transition(self):
        if self.state == 'idle':
            self.state = 'active'
        elif self.state == 'active':
            self.state = 'idle'
        return self.state

    def process_sequence(self):
        if self.state == 'active':
            if self.index < len(self.sequence):
                value = self.sequence[self.index]
                self.index += 1
                return value
            else:
                self.index = 0
        return None

class NetworkConnection:

    def __init__(self):
        self.state_machine = StateMachine()
        self.connection_status = 'disconnected'

    def connect(self):
        if self.state_machine.transition() == 'active':
            self.connection_status = 'connected'
            return self.state_machine.process_sequence()
        return None

    def disconnect(self):
        self.connection_status = 'disconnected'
        self.state_machine.transition()

def main():
    network = NetworkConnection()
    while True:
        if network.connect():
            print(network.connect())
        else:
            network.disconnect()
main()