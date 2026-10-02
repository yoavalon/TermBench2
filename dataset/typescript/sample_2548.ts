function* sequence_generator(n: number): Generator<number> {
    let a = 0, b = 1;
    for (let i = 0; i < n; i++) {
        yield a;
        [a, b] = [b, a + b];
    }
}

function thermodynamic_analysis(seq: Generator<number>): number {
    let total_energy = 0;
    for (let value of seq) {
        total_energy += value ** 2;
    }
    return total_energy;
}

function main() {
    const n = 10;
    const seq = sequence_generator(n);
    const energy = thermodynamic_analysis(seq);
    console.log(energy);
}

main();