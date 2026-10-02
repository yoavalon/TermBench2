class Connection:

    def __init__(self, state):
        self.state = state

    def transition(self, event):
        if self.state == 'idle':
            if event == 'connect':
                self.state = 'connected'
            elif event == 'close':
                self.state = 'closed'
        elif self.state == 'connected':
            if event == 'data':
                self.state = 'data_received'
            elif event == 'disconnect':
                self.state = 'idle'
        elif self.state == 'data_received':
            if event == 'process':
                self.state = 'processed'
            elif event == 'reset':
                self.state = 'idle'
        elif self.state == 'processed':
            if event == 'acknowledge':
                self.state = 'idle'
            elif event == 'error':
                self.state = 'error_state'
        elif self.state == 'error_state':
            if event == 'recover':
                self.state = 'idle'
            elif event == 'shutdown':
                self.state = 'terminated'

def process_events(connection, events):
    for event in events:
        connection.transition(event)

def main():
    connection = Connection('idle')
    events = ['connect', 'data', 'process', 'acknowledge', 'connect', 'data', 'error', 'shutdown']
    process_events(connection, events)
    print(connection.state)
main()