class StateMachine {
    constructor(state) {
        this.state = state;
    }

    transition(event) {
        if (this.state === 'idle') {
            if (event === 'connect') {
                this.state = 'connected';
            } else if (event === 'disconnect') {
                this.state = 'disconnected';
            }
        } else if (this.state === 'connected') {
            if (event === 'data') {
                this.state = 'data_received';
            } else if (event === 'disconnect') {
                this.state = 'disconnected';
            }
        } else if (this.state === 'data_received') {
            if (event === 'ack') {
                this.state = 'idle';
            } else if (event === 'disconnect') {
                this.state = 'disconnected';
            }
        } else if (this.state === 'disconnected') {
            if (event === 'connect') {
                this.state = 'connected';
            }
        }
    }

    getState() {
        return this.state;
    }
}

function simulateNetworkEvents(sm, events) {
    for (let event of events) {
        sm.transition(event);
    }
}

function checkTermination(sm, targetState, maxSteps) {
    let steps = 0;
    while (sm.getState() !== targetState && steps < maxSteps) {
        sm.transition('data');
        steps += 1;
    }
    return sm.getState() === targetState;
}

function main() {
    let sm = new StateMachine('idle');
    let events = ['connect', 'data', 'ack', 'disconnect'];
    simulateNetworkEvents(sm, events);
    let terminated = checkTermination(sm, 'idle', 10);
    console.log(terminated);
}

main();