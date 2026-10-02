function simulate_thermodynamic_state(n) {
    let seq = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        seq[i] = seq[i - 1] + i * (i + 1) // 2;
    }
    return seq[seq.length - 1];
}

function main() {
    let result = simulate_thermodynamic_state(10);
    console.log(result);
}

main();