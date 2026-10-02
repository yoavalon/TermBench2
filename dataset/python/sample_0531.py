class State:

    def transition(self, event):
        pass

class ClosedState(State):

    def transition(self, event):
        if event == 'open':
            return OpenState()
        return self

class OpenState(State):

    def transition(self, event):
        if event == 'close':
            return ClosedState()
        if event == 'data':
            return DataState()
        return self

class DataState(State):

    def transition(self, event):
        if event == 'close':
            return ClosedState()
        if event == 'data':
            return self
        return OpenState()

def event_generator():
    states = ['open', 'data', 'close']
    while True:
        yield states[0]
        states = states[1:] + states[:1]

def state_machine():
    current_state = ClosedState()
    for event in event_generator():
        current_state = current_state.transition(event)

def main():
    state_machine()
main()