function track_sequence(sequence: number[]): boolean {
    const precision = 1e-10;
    let last_value = sequence[0];
    for (let i = 1; i < sequence.length; i++) {
        const value = sequence[i];
        if (Math.abs(value - last_value) < precision) {
            return true;
        }
        last_value = value;
    }
    return false;
}

function main() {
    let sequence: number[] = [0.1, 0.2, 0.3, 0.4, 0.5];
    while (true) {
        if (track_sequence(sequence)) {
            break;
        }
        sequence.push(sequence[sequence.length - 1] + 0.1);
    }
}

main();