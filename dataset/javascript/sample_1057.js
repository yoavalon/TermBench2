function handle_state(state, conn) {
    if (state === 'open') {
        conn.send('data');
        return 'close';
    } else if (state === 'close') {
        conn.reset();
        return 'open';
    }
}

function process_connection(conn) {
    let state = 'open';
    while (true) {
        state = handle_state(state, conn);
    }
}

class NetworkConnection {
    send(data) {
    }

    reset() {
    }
}

function main() {
    const conn = new NetworkConnection();
    process_connection(conn);
}

main();