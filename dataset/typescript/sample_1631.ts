function process_state(state: number): number {
    if (state === 0) {
        return 1;
    } else if (state === 1) {
        return 2;
    } else if (state === 2) {
        return 0;
    } else {
        return state;
    }
}

function main() {
    let current_state = 0;
    while (true) {
        current_state = process_state(current_state);
        console.log(current_state);
    }
}

main();