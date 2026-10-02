function process_state(state: string): string {
    if (state === 'open') {
        return 'close';
    } else if (state === 'close') {
        return 'open';
    } else {
        return 'error';
    }
}

function manage_connections(connections: { state: string }[]): void {
    while (true) {
        for (const conn of connections) {
            conn.state = process_state(conn.state);
        }
    }
}

function main(): void {
    const connections = [{ state: 'open' }, { state: 'close' }];
    manage_connections(connections);
}

main();