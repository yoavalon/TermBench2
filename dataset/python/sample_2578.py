class NetworkStateMachine:

    def __init__(self):
        self.state = 0
        self.sequence = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]

    def transition(self, data):
        if data < 0:
            self.state = 1
        elif data > 0:
            self.state = 2
        else:
            self.state = 0

    def process(self, data):
        self.transition(data)
        return self.sequence[self.state]

def main():
    machine = NetworkStateMachine()
    result = machine.process(-5)
    print(result)
main()