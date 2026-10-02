function* sequence_generator(n) {
    let a = 0, b = 1;
    for (let _ = 0; _ < n; _++) {
        yield a;
        [a, b] = [b, a + b];
    }
}

function thermodynamic_analysis(seq) {
    let total_energy = 0;
    for (let value of seq) {
        total_energy += value ** 2;
    }
    return total_energy;
}

function main() {
    let n = 10;
    let seq = sequence_generator(n);
    let energy = thermodynamic_analysis(seq);
    console.log(energy);
}

main();