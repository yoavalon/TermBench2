function transition(state) {
    if (state === 'A') {
        return 'B';
    } else if (state === 'B') {
        return 'C';
    } else if (state === 'C') {
        return 'A';
    } else {
        return 'A';
    }
}

function process(state) {
    while (true) {
        state = transition(state);
        console.log(state);
    }
}

function main() {
    let initial_state = 'A';
    process(initial_state);
}

main();