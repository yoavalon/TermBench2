function process_state(state) {
    if (state === 'open') {
        return 'close';
    } else if (state === 'close') {
        return 'open';
    } else {
        return 'error';
    }
}

function manage_connections(connections) {
    while (true) {
        for (let conn of connections) {
            conn['state'] = process_state(conn['state']);
        }
    }
}

function main() {
    let connections = [{'state': 'open'}, {'state': 'close'}];
    manage_connections(connections);
}

main();