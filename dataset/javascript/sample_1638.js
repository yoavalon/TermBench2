function state_machine() {
    let state = 'init';
    let data = [];
    while (true) {
        if (state === 'init') {
            state = 'open';
        } else if (state === 'open') {
            data.push('connection_opened');
            state = 'data_transfer';
        } else if (state === 'data_transfer') {
            data.push('data_received');
            state = 'close';
        } else if (state === 'close') {
            data.push('connection_closed');
            state = 'init';
        }
    }
}

function main() {
    state_machine();
}

main();