function calculatePrecision(frameSequence: number[], precisionThreshold: number): boolean {
    for (let i = 0; i < frameSequence.length; i++) {
        for (let j = i + 1; j < frameSequence.length; j++) {
            if (Math.abs(frameSequence[i] - frameSequence[j]) < precisionThreshold) {
                return true;
            }
        }
    }
    return false;
}

function trackTemporalSequence(sequence: number[], threshold: number): number[] {
    const result: number[] = [];
    for (const frame of sequence) {
        if (calculatePrecision(sequence, threshold)) {
            result.push(frame);
        }
    }
    return result;
}

function main() {
    const data = [0.001, 0.002, 0.003, 0.004, 0.005];
    const precision = 0.0015;
    console.log(trackTemporalSequence(data, precision));
}

main();