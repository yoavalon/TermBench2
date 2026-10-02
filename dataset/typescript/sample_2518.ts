function generate_sequence(n: number): number[] {
    let seq: number[] = [1, 1];
    while (seq.length < n) {
        seq.push(seq[seq.length - 1] + seq[seq.length - 2]);
    }
    return seq;
}

function optimize_distribution(seq: number[], demand: number): string | number[] {
    let total_supply: number = seq.reduce((a, b) => a + b, 0);
    if (total_supply < demand) {
        return 'Insufficient supply';
    } else {
        return seq.filter(x => x <= demand);
    }
}

function main() {
    let n: number = 10;
    let demand: number = 15;
    let sequence: number[] = generate_sequence(n);
    let result: string | number[] = optimize_distribution(sequence, demand);
    console.log(result);
}

main();