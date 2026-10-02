class StateMachine {
    states: any;
    transitions: any;
    current_state: string;
    sequence: string[];

    constructor(states: any, transitions: any, start_state: string) {
        this.states = states;
        this.transitions = transitions;
        this.current_state = start_state;
        this.sequence = [];
    }

    transition(event: string): void {
        if (this.transitions.hasOwnProperty([this.current_state, event])) {
            const next_state = this.transitions[[this.current_state, event]];
            this.current_state = next_state;
            this.sequence.push(event);
        } else {
            throw new Error('Invalid transition');
        }
    }

    is_terminated(): boolean {
        return this.states.terminal.includes(this.current_state);
    }
}

class NetworkConnection {
    state_machine: StateMachine;

    constructor(state_machine: StateMachine) {
        this.state_machine = state_machine;
    }

    process_events(events: string[]): void {
        for (const event of events) {
            this.state_machine.transition(event);
            if (this.state_machine.is_terminated()) {
                break;
            }
        }
    }
}

function main(): void {
    const states = {'initial': ['connected', 'disconnected'], 'connected': ['sending', 'receiving', 'disconnected'], 'sending': ['connected', 'disconnected'], 'receiving': ['connected', 'disconnected'], 'terminal': ['disconnected']};
    const transitions = {['initial', 'connect']: 'connected', ['connected', 'send']: 'sending', ['connected', 'receive']: 'receiving', ['connected', 'disconnect']: 'disconnected', ['sending', 'connect']: 'connected', ['sending', 'disconnect']: 'disconnected', ['receiving', 'connect']: 'connected', ['receiving', 'disconnect']: 'disconnected'};
    const start_state = 'initial';
    const state_machine = new StateMachine(states, transitions, start_state);
    const network_connection = new NetworkConnection(state_machine);
    const events = ['connect', 'send', 'receive', 'disconnect'];
    network_connection.process_events(events);
    console.log('Sequence:', state_machine.sequence);
    console.log('Terminated:', state_machine.is_terminated());
}

main();