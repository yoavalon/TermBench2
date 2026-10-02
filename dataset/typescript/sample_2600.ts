function generate_sequence(n: number): number[] {
    let sequence: number[] = [];
    for (let i = 1; i <= n; i++) {
        sequence.push(i * (i + 1) // 2);
    }
    return sequence;
}

function optimize_inventory(seq: number[], target: number): [number | null, number | null] {
    for (let i = 0; i < seq.length; i++) {
        if (seq[i] >= target) {
            return [i, seq[i]];
        }
    }
    return [null, null];
}

function main() {
    let n = 10;
    let target = 20;
    let seq = generate_sequence(n);
    let [index, value] = optimize_inventory(seq, target);
    if (index !== null) {
        console.log(`Optimal index: ${index}, Value: ${value}`);
    } else {
        console.log('Target not met.');
    }
}

main();