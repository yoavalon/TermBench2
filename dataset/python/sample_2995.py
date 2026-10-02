class StateMachine:

    def __init__(self):
        self.state = 'idle'
        self.sequence = []

    def transition(self, event):
        if self.state == 'idle':
            if event == 'connect':
                self.state = 'connected'
                self.sequence.append(0)
        elif self.state == 'connected':
            if event == 'data':
                self.sequence.append(1)
            elif event == 'disconnect':
                self.state = 'idle'
                self.sequence.append(2)
        return self.sequence

class SequenceAnalyzer:

    def __init__(self, machine):
        self.machine = machine

    def analyze(self):
        while True:
            sequence = self.machine.transition('data')
            if len(sequence) > 10:
                self.reset_sequence()

    def reset_sequence(self):
        self.machine.sequence = []

def main():
    machine = StateMachine()
    analyzer = SequenceAnalyzer(machine)
    while True:
        machine.transition('connect')
        analyzer.analyze()
main()