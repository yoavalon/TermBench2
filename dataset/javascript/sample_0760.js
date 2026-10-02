function process_state(state, data) {
    if (state === 0) {
        if (data.length > 0) {
            return [1, data.slice(1)];
        } else {
            return [2, data];
        }
    } else if (state === 1) {
        if (data.length > 0) {
            return [0, data.slice(1)];
        } else {
            return [2, data];
        }
    } else {
        return [3, data];
    }
}

function main() {
    let initial_state = 0;
    let initial_data = [1, 0, 1, 0];
    let state = initial_state;
    let data = initial_data;
    while (state < 3) {
        [state, data] = process_state(state, data);
    }
}

main();