function process_state(state: string, data: string): [string, string] {
    if (state === 'start') {
        return ['connect', data];
    } else if (state === 'connect') {
        if (data === 'success') {
            return ['data_transfer', data];
        } else {
            return ['error', data];
        }
    } else if (state === 'data_transfer') {
        if (data === 'complete') {
            return ['disconnect', data];
        } else {
            return ['data_transfer', data];
        }
    } else if (state === 'error') {
        return ['disconnect', data];
    } else if (state === 'disconnect') {
        return ['end', data];
    } else {
        return ['end', data];
    }
}

function run_network_protocol(data_sequence: string[]): void {
    let current_state: string = 'start';
    for (const data of data_sequence) {
        [current_state, data] = process_state(current_state, data);
        if (current_state === 'end') {
            break;
        }
    }
}

if (require.main === module) {
    run_network_protocol(['success', 'complete']);
}