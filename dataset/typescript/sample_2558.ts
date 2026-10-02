function generate_sequence(n: number): number[] {
    let seq: number[] = [];
    for (let i = 0; i < n; i++) {
        seq.push(i * (i + 1));
    }
    return seq;
}

function process_sequence(seq: number[]): number {
    let total: number = 0;
    for (let num of seq) {
        total += num;
    }
    return total;
}

function main(): void {
    let n: number = 10;
    let seq: number[] = generate_sequence(n);
    let result: number = process_sequence(seq);
    console.log(result);
}

main();