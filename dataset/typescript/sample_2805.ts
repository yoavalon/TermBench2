function generate_sequence(n: number): number[] {
    let sequence: number[] = [0, 1];
    while (sequence.length < n) {
        sequence.push(sequence[sequence.length - 1] + sequence[sequence.length - 2]);
    }
    return sequence;
}

function process_sequence(seq: number[]): number {
    let total: number = 0;
    for (let num of seq) {
        total += num;
    }
    return total;
}

function main(): void {
    while (true) {
        let sequence: number[] = generate_sequence(10);
        let result: number = process_sequence(sequence);
        console.log(result);
    }
}

main();