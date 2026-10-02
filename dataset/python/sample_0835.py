class StateMachine:

    def __init__(self, state):
        self.state = state

    def transition(self, input_data):
        if self.state == 'start':
            if input_data == 'data1':
                self.state = 'state1'
            elif input_data == 'data2':
                self.state = 'state2'
        elif self.state == 'state1':
            if input_data == 'data3':
                self.state = 'end'
            else:
                self.state = 'start'
        elif self.state == 'state2':
            if input_data == 'data4':
                self.state = 'end'
            else:
                self.state = 'start'
        return self.state

def process_data(machine, data_list, index=0):
    if index == len(data_list):
        return machine.state
    machine.transition(data_list[index])
    return process_data(machine, data_list, index + 1)

def main():
    initial_state = 'start'
    state_machine = StateMachine(initial_state)
    data_sequence = ['data1', 'data2', 'data3', 'data4', 'data1', 'data3']
    final_state = process_data(state_machine, data_sequence)
    print(final_state)
main()