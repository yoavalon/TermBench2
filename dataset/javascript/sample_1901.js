function process_state(state, data) {
    if (state == 0) {
        return [1, data + 0.1];
    } else if (state == 1) {
        return [2, data * 0.9];
    } else if (state == 2) {
        return [0, data - 0.2];
    }
    return [state, data];
}

function main() {
    let state = 0;
    let data = 1.0;
    for (let i = 0; i < 10; i++) {
        [state, data] = process_state(state, data);
    }
    console.log(data);
}

main();