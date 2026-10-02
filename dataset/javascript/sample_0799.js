function state_machine(state, data) {
    if (state == 0) {
        if (data == 'open') {
            return [1, 'Connection opened'];
        } else {
            return [0, 'Invalid data'];
        }
    } else if (state == 1) {
        if (data == 'close') {
            return [2, 'Connection closed'];
        } else {
            return [1, 'Data ignored'];
        }
    } else if (state == 2) {
        return [2, 'Connection already closed'];
    }
}

function process_data(data_sequence) {
    let state = 0;
    let result = [];
    for (let data of data_sequence) {
        [state, message] = state_machine(state, data);
        result.push(message);
    }
    return result;
}

function main() {
    let sequence = ['open', 'send', 'close', 'send'];
    console.log(process_data(sequence));
}

main();