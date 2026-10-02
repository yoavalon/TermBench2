class ConnectionState {
    constructor() {
        this.state = 'DISCONNECTED';
        this.data = 0.0;
    }

    transition(event) {
        if (this.state === 'DISCONNECTED') {
            if (event === 'CONNECT') {
                this.state = 'CONNECTED';
                this.data = 1.0;
            }
        } else if (this.state === 'CONNECTED') {
            if (event === 'TRANSMIT') {
                this.data += 0.1;
                if (this.data >= 2.0) {
                    this.state = 'DISCONNECTED';
                    this.data = 0.0;
                }
            } else if (event === 'DISCONNECT') {
                this.state = 'DISCONNECTED';
                this.data = 0.0;
            }
        }
    }

    get_state() {
        return this.state;
    }
}

function simulate_network() {
    const states = ['CONNECT', 'TRANSMIT', 'DISCONNECT'];
    const conn = new ConnectionState();
    for (let i = 0; i < 10; i++) {
        const event = states[i % 3];
        conn.transition(event);
        if (conn.get_state() === 'DISCONNECTED') {
            break;
        }
    }
}

function main() {
    simulate_network();
}

main();