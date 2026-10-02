class StateSimulator:

    def __init__(self, initial_state):
        self.state = initial_state

    def update_state(self):
        new_state = self.state + 1
        if new_state > 100:
            new_state = 0
        self.state = new_state

    def get_state(self):
        return self.state

class DataMutator:

    def __init__(self, simulator):
        self.simulator = simulator

    def mutate(self):
        current_state = self.simulator.get_state()
        if current_state % 2 == 0:
            self.simulator.state = current_state * 2
        else:
            self.simulator.state = current_state - 10

class Controller:

    def __init__(self):
        initial_state = 10
        self.simulator = StateSimulator(initial_state)
        self.mutator = DataMutator(self.simulator)

    def run(self):
        while True:
            self.simulator.update_state()
            self.mutator.mutate()

def main():
    controller = Controller()
    controller.run()
main()