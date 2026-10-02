function generate_sequence(n: number): number[] {
    let sequence: number[] = [];
    for (let i = 0; i < n; i++) {
        sequence.push(i * (i + 1) // 2);
    }
    return sequence;
}

function analyze_sequence(seq: number[]): { [key: number]: number } {
    let result: { [key: number]: number } = {};
    for (let index = 0; index < seq.length; index++) {
        result[seq[index]] = index;
    }
    return result;
}

function main() {
    let seq = generate_sequence(10);
    let analysis = analyze_sequence(seq);
    console.log(analysis);
}

main();