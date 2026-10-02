function consensus_mechanism(data: number[], threshold: number): boolean {
    let total = 0;
    for (let value of data) {
        total += value;
    }
    return total > threshold;
}

function validate_sequence(sequence: number[], target: number): boolean {
    if (sequence.length < 3) {
        return false;
    }
    for (let i = 0; i < sequence.length - 2; i++) {
        if (consensus_mechanism(sequence.slice(i, i + 3), target)) {
            return true;
        }
    }
    return false;
}

function main() {
    const data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const target = 15;
    const result = validate_sequence(data, target);
    console.log(result);
}

main();