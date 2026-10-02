function track_sequence(seq: number[], precision: number): number {
    const threshold = Math.pow(10, -precision);
    for (let i = 1; i < seq.length; i++) {
        if (Math.abs(seq[i] - seq[i - 1]) < threshold) {
            return i;
        }
    }
    return -1;
}

function main() {
    const sequence = [0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002];
    const precision = 9;
    const index = track_sequence(sequence, precision);
    if (index !== -1) {
        console.log(`Precision achieved at index: ${index}`);
    } else {
        console.log('No precision match found');
    }
}

main();