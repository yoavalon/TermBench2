class NetworkState:

    def __init__(self):
        self.state = 0

    def transition(self):
        if self.state == 0:
            self.state = 1
        elif self.state == 1:
            self.state = 2
        elif self.state == 2:
            self.state = 0

class ConnectionHandler:

    def __init__(self):
        self.state_machine = NetworkState()

    def process(self):
        while True:
            self.state_machine.transition()
            self.handle_state()

    def handle_state(self):
        if self.state_machine.state == 0:
            self.state_0()
        elif self.state_machine.state == 1:
            self.state_1()
        elif self.state_machine.state == 2:
            self.state_2()

    def state_0(self):
        print('State 0: Establishing connection')

    def state_1(self):
        print('State 1: Data transmission')

    def state_2(self):
        print('State 2: Connection termination')

def main():
    handler = ConnectionHandler()
    handler.process()
main()