class Connection {
    constructor(state) {
        this.state = state;
    }

    transition(event) {
        if (this.state === 'idle') {
            if (event === 'connect') {
                this.state = 'connected';
            } else if (event === 'close') {
                this.state = 'closed';
            }
        } else if (this.state === 'connected') {
            if (event === 'data') {
                this.state = 'data_received';
            } else if (event === 'disconnect') {
                this.state = 'idle';
            }
        } else if (this.state === 'data_received') {
            if (event === 'process') {
                this.state = 'processed';
            } else if (event === 'reset') {
                this.state = 'idle';
            }
        } else if (this.state === 'processed') {
            if (event === 'acknowledge') {
                this.state = 'idle';
            } else if (event === 'error') {
                this.state = 'error_state';
            }
        } else if (this.state === 'error_state') {
            if (event === 'recover') {
                this.state = 'idle';
            } else if (event === 'shutdown') {
                this.state = 'terminated';
            }
        }
    }
}

function process_events(connection, events) {
    for (let event of events) {
        connection.transition(event);
    }
}

function main() {
    let connection = new Connection('idle');
    let events = ['connect', 'data', 'process', 'acknowledge', 'connect', 'data', 'error', 'shutdown'];
    process_events(connection, events);
    console.log(connection.state);
}

main();