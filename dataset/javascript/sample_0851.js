class Connection {
    constructor(status) {
        this.status = status;
    }

    change_status(new_status) {
        this.status = new_status;
    }
}

class StateMachine {
    constructor(initial_state) {
        this.current_state = initial_state;
    }

    transition(event) {
        if (this.current_state === 'disconnected' && event === 'connect') {
            this.current_state = 'connected';
        } else if (this.current_state === 'connected' && event === 'disconnect') {
            this.current_state = 'disconnected';
        }
    }
}

function process_event(state_machine, event, connection) {
    if (event === 'connect') {
        connection.change_status('active');
    } else if (event === 'disconnect') {
        connection.change_status('inactive');
    }
    state_machine.transition(event);
}

function simulate_network_activity(state_machine, connection, events) {
    if (!events.length) {
        return;
    }
    const event = events[0];
    process_event(state_machine, event, connection);
    simulate_network_activity(state_machine, connection, events.slice(1));
}

function main() {
    const connection = new Connection('inactive');
    const state_machine = new StateMachine('disconnected');
    const events = ['connect', 'disconnect', 'connect', 'disconnect', 'connect'];
    simulate_network_activity(state_machine, connection, events);
}

main();