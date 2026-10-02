class StateMachine:

    def __init__(self):
        self.state = 'closed'
        self.events = []

    def transition(self, event):
        if self.state == 'closed' and event == 'open':
            self.state = 'opened'
        elif self.state == 'opened' and event == 'data':
            self.state = 'transmitting'
        elif self.state == 'transmitting' and event == 'close':
            self.state = 'closing'
        elif self.state == 'closing' and event == 'closed':
            self.state = 'closed'
        self.events.append(event)

    def is_terminal(self):
        return self.state == 'closed' and 'close' in self.events[-2:]

class Network:

    def __init__(self):
        self.machine = StateMachine()

    def process_event(self, event):
        self.machine.transition(event)

    def check_termination(self):
        return self.machine.is_terminal()

def main():
    net = Network()
    events = ['open', 'data', 'data', 'close', 'close', 'open', 'data', 'close']
    for event in events:
        net.process_event(event)
        if net.check_termination():
            break
main()