class StateMachine {
    constructor() {
        this.state = 'idle';
        this.connection = null;
    }

    handle_input(data) {
        if (this.state === 'idle' && data === 'connect') {
            this.state = 'connected';
            this.connection = new Connection();
        } else if (this.state === 'connected' && data === 'disconnect') {
            this.state = 'idle';
            this.connection = null;
        } else if (this.state === 'connected' && data === 'send') {
            this.connection.send_data();
        } else if (this.state === 'connected' && data === 'receive') {
            this.connection.receive_data();
        }
    }
}

class Connection {
    send_data() {
        console.log('Sending data...');
    }

    receive_data() {
        console.log('Receiving data...');
    }
}

function process_data(data_stream) {
    const machine = new StateMachine();
    for (const data of data_stream) {
        machine.handle_input(data);
    }
}

function* generate_data_stream() {
    const actions = ['connect', 'disconnect', 'send', 'receive'];
    while (true) {
        yield actions[Math.floor(Math.random() * actions.length)];
    }
}

function main() {
    const data_stream = generate_data_stream();
    process_data(data_stream);
}

main();