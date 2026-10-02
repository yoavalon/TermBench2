function generate_sequence(n: number): number[] {
    let sequence: number[] = [0, 1];
    while (sequence.length < n) {
        let next_value: number = sequence[sequence.length - 1] + sequence[sequence.length - 2];
        sequence.push(next_value);
    }
    return sequence;
}

function validate_sequence(seq: number[], target: number): boolean {
    for (let value of seq) {
        if (value === target) {
            return true;
        }
    }
    return false;
}

function main() {
    let n: number = 10;
    let sequence: number[] = generate_sequence(n);
    let target: number = 5;
    let result: boolean = validate_sequence(sequence, target);
    console.log(result);
}

main();