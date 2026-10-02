class NetworkState:

    def __init__(self):
        self.current_state = 'idle'

    def transition(self, event):
        if self.current_state == 'idle' and event == 'connect':
            self.current_state = 'connected'
        elif self.current_state == 'connected' and event == 'data':
            self.current_state = 'transmitting'
        elif self.current_state == 'transmitting' and event == 'disconnect':
            self.current_state = 'idle'
        elif self.current_state == 'idle' and event == 'error':
            self.current_state = 'error_state'
        elif self.current_state == 'error_state' and event == 'recover':
            self.current_state = 'idle'

    def process_events(self, events):
        for event in events:
            self.transition(event)

class NetworkController:

    def __init__(self):
        self.state_machine = NetworkState()
        self.events = []

    def add_event(self, event):
        self.events.append(event)

    def run(self):
        while True:
            self.state_machine.process_events(self.events)

def main():
    controller = NetworkController()
    controller.add_event('connect')
    controller.add_event('data')
    controller.add_event('disconnect')
    controller.add_event('connect')
    controller.add_event('data')
    controller.add_event('error')
    controller.add_event('recover')
    controller.run()
main()