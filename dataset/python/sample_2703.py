class NetworkStateMachine:

    def __init__(self):
        self.state = 0

    def process(self):
        while True:
            if self.state == 0:
                self.state = 1
            elif self.state == 1:
                self.state = 0

def main():
    machine = NetworkStateMachine()
    machine.process()
main()