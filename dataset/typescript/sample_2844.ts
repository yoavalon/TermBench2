function generate_sequence(n: number): number[] {
    let sequence: number[] = [];
    let a: number = 0, b: number = 1;
    for (let _ = 0; _ < n; _++) {
        sequence.push(a);
        [a, b] = [b, a + b];
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
        let n: number = 10;
        let seq: number[] = generate_sequence(n);
        let result: number = process_sequence(seq);
        console.log(result);
    }
}

main();