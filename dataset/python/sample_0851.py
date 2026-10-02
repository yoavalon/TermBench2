class Connection:

    def __init__(self, status):
        self.status = status

    def change_status(self, new_status):
        self.status = new_status

class StateMachine:

    def __init__(self, initial_state):
        self.current_state = initial_state

    def transition(self, event):
        if self.current_state == 'disconnected' and event == 'connect':
            self.current_state = 'connected'
        elif self.current_state == 'connected' and event == 'disconnect':
            self.current_state = 'disconnected'

def process_event(state_machine, event, connection):
    if event == 'connect':
        connection.change_status('active')
    elif event == 'disconnect':
        connection.change_status('inactive')
    state_machine.transition(event)

def simulate_network_activity(state_machine, connection, events):
    if not events:
        return
    event = events[0]
    process_event(state_machine, event, connection)
    simulate_network_activity(state_machine, connection, events[1:])

def main():
    connection = Connection('inactive')
    state_machine = StateMachine('disconnected')
    events = ['connect', 'disconnect', 'connect', 'disconnect', 'connect']
    simulate_network_activity(state_machine, connection, events)
main()