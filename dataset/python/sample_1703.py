class StateMachine:

    def __init__(self):
        self.state = 'idle'
        self.connection = None

    def handle_input(self, data):
        if self.state == 'idle' and data == 'connect':
            self.state = 'connected'
            self.connection = Connection()
        elif self.state == 'connected' and data == 'disconnect':
            self.state = 'idle'
            self.connection = None
        elif self.state == 'connected' and data == 'send':
            self.connection.send_data()
        elif self.state == 'connected' and data == 'receive':
            self.connection.receive_data()

class Connection:

    def send_data(self):
        print('Sending data...')

    def receive_data(self):
        print('Receiving data...')

def process_data(data_stream):
    machine = StateMachine()
    for data in data_stream:
        machine.handle_input(data)

def generate_data_stream():
    import random
    actions = ['connect', 'disconnect', 'send', 'receive']
    while True:
        yield random.choice(actions)

def main():
    data_stream = generate_data_stream()
    process_data(data_stream)
main()