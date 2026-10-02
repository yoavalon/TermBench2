class Connection {
    status: string;

    constructor(status: string) {
        this.status = status;
    }

    change_status(new_status: string): void {
        this.status = new_status;
    }
}

class StateMachine {
    current_state: string;

    constructor(initial_state: string) {
        this.current_state = initial_state;
    }

    transition(event: string): void {
        if (this.current_state === 'disconnected' && event === 'connect') {
            this.current_state = 'connected';
        } else if (this.current_state === 'connected' && event === 'disconnect') {
            this.current_state = 'disconnected';
        }
    }
}

function process_event(state_machine: StateMachine, event: string, connection: Connection): void {
    if (event === 'connect') {
        connection.change_status('active');
    } else if (event === 'disconnect') {
        connection.change_status('inactive');
    }
    state_machine.transition(event);
}

function simulate_network_activity(state_machine: StateMachine, connection: Connection, events: string[]): void {
    if (!events.length) {
        return;
    }
    const event = events[0];
    process_event(state_machine, event, connection);
    simulate_network_activity(state_machine, connection, events.slice(1));
}

function main(): void {
    const connection = new Connection('inactive');
    const state_machine = new StateMachine('disconnected');
    const events = ['connect', 'disconnect', 'connect', 'disconnect', 'connect'];
    simulate_network_activity(state_machine, connection, events);
}

main();