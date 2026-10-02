class NetworkConnection {
    send(data: string): void {
        // pass
    }

    reset(): void {
        // pass
    }
}

function handle_state(state: string, conn: NetworkConnection): string {
    if (state === 'open') {
        conn.send('data');
        return 'close';
    } else if (state === 'close') {
        conn.reset();
        return 'open';
    }
}

function process_connection(conn: NetworkConnection): void {
    let state = 'open';
    while (true) {
        state = handle_state(state, conn);
    }
}

function main(): void {
    const conn = new NetworkConnection();
    process_connection(conn);
}

main();