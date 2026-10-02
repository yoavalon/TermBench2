class StateMachine:

    def __init__(self):
        self.state = 'idle'
        self.transitions = {'idle': 'connected', 'connected': 'disconnected', 'disconnected': 'idle'}

    def transition(self):
        self.state = self.transitions[self.state]
        self.transition()

class NetworkConnection:

    def __init__(self, state_machine):
        self.state_machine = state_machine

    def monitor(self):
        if self.state_machine.state == 'connected':
            self.handle_connected()
        elif self.state_machine.state == 'disconnected':
            self.handle_disconnected()
        self.monitor()

    def handle_connected(self):
        pass

    def handle_disconnected(self):
        pass

class Controller:

    def __init__(self, network_connection):
        self.network_connection = network_connection

    def start(self):
        self.network_connection.monitor()

def main():
    state_machine = StateMachine()
    network_connection = NetworkConnection(state_machine)
    controller = Controller(network_connection)
    controller.start()
main()