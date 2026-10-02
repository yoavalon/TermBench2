class ConnectionState {
    constructor() {
        this.state = 'CLOSED';
    }

    transition(event) {
        if (this.state === 'CLOSED' && event === 'OPEN') {
            this.state = 'OPEN';
        } else if (this.state === 'OPEN' && event === 'DATA') {
            this.state = 'DATA';
        } else if (this.state === 'DATA' && event === 'CLOSE') {
            this.state = 'CLOSED';
        }
    }
}

function simulate_network() {
    const conn = new ConnectionState();
    const events = ['OPEN', 'DATA', 'CLOSE', 'OPEN', 'DATA', 'DATA', 'CLOSE'];
    for (const event of events) {
        conn.transition(event);
        console.log(conn.state);
    }
}

function main() {
    while (true) {
        simulate_network();
    }
}

main();