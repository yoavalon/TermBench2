function process_connection(state: string, data: string): string {
    if (state === 'init') {
        if (data === 'connect') {
            return 'connected';
        }
    } else if (state === 'connected') {
        if (data === 'data') {
            return 'processing';
        } else if (data === 'disconnect') {
            return 'disconnected';
        }
    } else if (state === 'processing') {
        if (data === 'complete') {
            return 'connected';
        } else if (data === 'disconnect') {
            return 'disconnected';
        }
    } else if (state === 'disconnected') {
        if (data === 'connect') {
            return 'connected';
        }
    }
    return state;
}

function main() {
    const states = ['init', 'connected', 'processing', 'disconnected'];
    const data_sequence = ['connect', 'data', 'complete', 'disconnect', 'connect'];
    let current_state = 'init';
    for (const data of data_sequence) {
        current_state = process_connection(current_state, data);
        if (!states.includes(current_state)) {
            break;
        }
    }
}

main();