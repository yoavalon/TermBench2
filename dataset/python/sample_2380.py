class NetworkConnectionState:

    def __init__(self):
        self.state = 'disconnected'
        self.data_buffer = []
        self.error_count = 0

    def transition(self, event):
        if self.state == 'disconnected' and event == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'send':
            self.data_buffer.append('data')
        elif self.state == 'connected' and event == 'receive':
            if self.data_buffer:
                self.data_buffer.pop(0)
            else:
                self.error_count += 1

class NetworkController:

    def __init__(self):
        self.connection = NetworkConnectionState()
        self.events = ['connect', 'send', 'receive']

    def process_events(self):
        while True:
            for event in self.events:
                self.connection.transition(event)

class Monitor:

    def __init__(self, controller):
        self.controller = controller

    def check_state(self):
        while True:
            if self.controller.connection.error_count >= 3:
                print('Error threshold reached, resetting...')
                self.controller.connection.error_count = 0

def main():
    controller = NetworkController()
    monitor = Monitor(controller)
    controller.process_events()
    monitor.check_state()
main()