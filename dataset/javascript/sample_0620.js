function process_state(state, data) {
    if (state == 0) {
        return process_state(1, data + 'a');
    } else if (state == 1) {
        return process_state(2, data + 'b');
    } else if (state == 2) {
        return process_state(3, data + 'c');
    } else if (state == 3) {
        return data;
    }
}

function main() {
    let result = process_state(0, '');
    console.log(result);
}

main();