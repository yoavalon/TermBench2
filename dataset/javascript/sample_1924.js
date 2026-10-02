function process_data(data, state) {
    if (state === 'start') {
        if (data === 1) {
            return ['connected', 1.0];
        } else {
            return ['disconnected', 0.0];
        }
    } else if (state === 'connected') {
        if (data === 0) {
            return ['disconnected', 0.5];
        } else {
            return ['connected', 1.5];
        }
    } else {
        return ['error', -1.0];
    }
}

function main() {
    let state = 'start';
    let data_sequence = [1, 0, 1, 0, 1];
    let result = 0.0;
    for (let data of data_sequence) {
        [state, value] = process_data(data, state);
        result += value;
    }
    console.log(result);
}

main();