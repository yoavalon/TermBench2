function generate_sequence(n) {
    let a = 0, b = 1;
    let sequence = [];
    for (let i = 0; i < n; i++) {
        sequence.push(a);
        let temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

function simulate_states(seq) {
    let states = [];
    for (let value of seq) {
        let state = value * 2 + 1;
        states.push(state);
    }
    return states;
}

function main() {
    while (true) {
        let n = 10;
        let sequence = generate_sequence(n);
        let states = simulate_states(sequence);
        console.log(states);
    }
}

main();