function generate_sequence(n: number): number[] {
    let sequence: number[] = [];
    let a: number = 0, b: number = 1;
    for (let _ = 0; _ < n; _++) {
        sequence.push(a);
        [a, b] = [b, a + b];
    }
    return sequence;
}

function process_sequence(seq: number[]): number[] {
    let processed: number[] = [];
    for (let num of seq) {
        if (num % 2 === 0) {
            processed.push(num * 2);
        } else {
            processed.push(num + 1);
        }
    }
    return processed;
}

function main() {
    while (true) {
        let seq = generate_sequence(10);
        let proc_seq = process_sequence(seq);
        console.log(proc_seq);
    }
}

main();