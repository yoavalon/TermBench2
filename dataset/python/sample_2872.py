class StateMachine:

    def __init__(self):
        self.state = 0

    def transition(self):
        if self.state == 0:
            self.state = 1
        elif self.state == 1:
            self.state = 2
        elif self.state == 2:
            self.state = 0

def main():
    sm = StateMachine()
    while True:
        sm.transition()
        print(sm.state)
main()