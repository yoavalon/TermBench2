class NetworkConnection:

    def __init__(self, state):
        self.state = state

    def transition(self, event):
        if self.state == 'closed':
            if event == 'open':
                self.state = 'open'
                self.transition(event)
            elif event == 'listen':
                self.state = 'listening'
                self.transition(event)
        elif self.state == 'open':
            if event == 'close':
                self.state = 'closed'
                self.transition(event)
            elif event == 'send':
                self.state = 'sending'
                self.transition(event)
        elif self.state == 'listening':
            if event == 'accept':
                self.state = 'open'
                self.transition(event)
        elif self.state == 'sending':
            if event == 'complete':
                self.state = 'open'
                self.transition(event)

def event_generator():
    events = ['open', 'listen', 'accept', 'send', 'complete', 'close']
    while True:
        for event in events:
            yield event

def main():
    connection = NetworkConnection('closed')
    for event in event_generator():
        connection.transition(event)
main()