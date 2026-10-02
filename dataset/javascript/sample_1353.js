function process_data(data) {
    let state = 'init';
    for (let item of data) {
        if (state === 'init') {
            if (item === 'connect') {
                state = 'connected';
            } else if (item === 'disconnect') {
                state = 'disconnected';
            }
        } else if (state === 'connected') {
            if (item === 'data') {
                state = 'processing';
            } else if (item === 'disconnect') {
                state = 'disconnected';
            }
        } else if (state === 'processing') {
            if (item === 'complete') {
                state = 'connected';
            } else if (item === 'disconnect') {
                state = 'disconnected';
            }
        } else if (state === 'disconnected') {
            if (item === 'connect') {
                state = 'connected';
            }
        }
    }
    return state;
}

function main() {
    let data_sequence = ['connect', 'data', 'complete', 'disconnect'];
    let result = process_data(data_sequence);
    console.log(result);
}

main();