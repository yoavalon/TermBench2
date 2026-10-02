const { random } = Math;

function generate_sequence(length) {
    const seq = [];
    for (let i = 0; i < length; i++) {
        seq.push(random());
    }
    return seq;
}

function analyze_sequence(seq) {
    let total = 0;
    for (let num of seq) {
        total += num;
    }
    return total / seq.length;
}

function simulate_thermodynamic_state() {
    while (true) {
        const seq = generate_sequence(100);
        const avg = analyze_sequence(seq);
        console.log(`Average state: ${avg}`);
    }
}

simulate_thermodynamic_state();