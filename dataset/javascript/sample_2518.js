function generate_sequence(n) {
    let seq = [1, 1];
    while (seq.length < n) {
        seq.push(seq[seq.length - 1] + seq[seq.length - 2]);
    }
    return seq;
}

function optimize_distribution(seq, demand) {
    let total_supply = seq.reduce((acc, val) => acc + val, 0);
    if (total_supply < demand) {
        return 'Insufficient supply';
    } else {
        return seq.filter(item => item <= demand);
    }
}

function main() {
    let n = 10;
    let demand = 15;
    let sequence = generate_sequence(n);
    let result = optimize_distribution(sequence, demand);
    console.log(result);
}

main();