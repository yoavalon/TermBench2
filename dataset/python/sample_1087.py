class StateMachine:

    def __init__(self):
        self.state = 'idle'

    def transition(self):
        if self.state == 'idle':
            self.state = 'connecting'
        elif self.state == 'connecting':
            self.state = 'connected'
        elif self.state == 'connected':
            self.state = 'disconnected'
        else:
            self.state = 'idle'

def recursive_function(sm):
    sm.transition()
    recursive_function(sm)

def main():
    sm = StateMachine()
    recursive_function(sm)
main()