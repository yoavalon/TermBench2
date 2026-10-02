import random

class NetworkConnection:

    def __init__(self, state):
        self.state = state

    def transition(self, event):
        if self.state == 'disconnected' and event == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'disconnected'
        elif self.state == 'connected' and event == 'error':
            self.state = 'error'
        elif self.state == 'error' and event == 'recover':
            self.state = 'connected'

class EventGenerator:

    def __init__(self):
        self.events = ['connect', 'disconnect', 'error', 'recover']

    def generate(self):
        return random.choice(self.events)

class StateSimulator:

    def __init__(self):
        self.connection = NetworkConnection('disconnected')
        self.generator = EventGenerator()

    def simulate(self):
        while True:
            event = self.generator.generate()
            self.connection.transition(event)
            print(f'Event: {event}, State: {self.connection.state}')

def main():
    simulator = StateSimulator()
    simulator.simulate()
main()