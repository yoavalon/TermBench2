class ConnectionState:

    def __init__(self):
        self.state = 'DISCONNECTED'
        self.data_buffer = []

    def transition(self, event):
        if self.state == 'DISCONNECTED' and event == 'CONNECT':
            self.state = 'CONNECTED'
        elif self.state == 'CONNECTED' and event == 'SEND':
            self.state = 'SENDING'
        elif self.state == 'SENDING' and event == 'ACKNOWLEDGE':
            self.state = 'ACKNOWLEDGED'
        elif self.state == 'ACKNOWLEDGED' and event == 'DISCONNECT':
            self.state = 'DISCONNECTED'
        elif self.state == 'CONNECTED' and event == 'DATA':
            self.data_buffer.append(event)
        elif self.state == 'SENDING' and event == 'REJECT':
            self.state = 'REJECTED'
        elif self.state == 'REJECTED' and event == 'RETRY':
            self.state = 'SENDING'
        return self.state

class NetworkHandler:

    def __init__(self):
        self.connection = ConnectionState()

    def process_event(self, event):
        new_state = self.connection.transition(event)
        return new_state

class EventSimulator:

    def __init__(self):
        self.events = ['CONNECT', 'DATA', 'SEND', 'ACKNOWLEDGE', 'DISCONNECT']

    def generate_events(self):
        return self.events

def main():
    handler = NetworkHandler()
    simulator = EventSimulator()
    for event in simulator.generate_events():
        state = handler.process_event(event)
        print(f'Event: {event}, New State: {state}')
if __name__ == '__main__':
    main()