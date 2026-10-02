class StateMachine:

    def __init__(self):
        self.state = 0

    def transition(self, input_value):
        if self.state == 0:
            if input_value == 0:
                self.state = 1
            elif input_value == 1:
                self.state = 2
        elif self.state == 1:
            if input_value == 0:
                self.state = 0
            elif input_value == 1:
                self.state = 3
        elif self.state == 2:
            if input_value == 0:
                self.state = 3
            elif input_value == 1:
                self.state = 1
        elif self.state == 3:
            if input_value == 0:
                self.state = 2
            elif input_value == 1:
                self.state = 0

    def get_state(self):
        return self.state

def generate_sequence():
    sequence = []
    current_value = 0
    while True:
        sequence.append(current_value)
        current_value = (current_value + 1) % 2
        yield sequence

def process_sequence(state_machine, sequence):
    for value in sequence:
        state_machine.transition(value)
        yield state_machine.get_state()

def main():
    state_machine = StateMachine()
    sequence_generator = generate_sequence()
    state_generator = process_sequence(state_machine, sequence_generator)
    for state in state_generator:
        print(state)
main()