function calculateHash(data: string, previousHash: number): number {
    let result = previousHash;
    for (let byte of new TextEncoder().encode(data)) {
        result = (result * byte) % 10007;
    }
    return result;
}

function consensusSequence(length: number, seed: number): number[] {
    const sequence: number[] = [seed];
    let currentHash = seed;
    for (let i = 1; i < length; i++) {
        currentHash = calculateHash(sequence[sequence.length - 1].toString(), currentHash);
        sequence.push(currentHash);
    }
    return sequence;
}

function main() {
    const sequenceLength = 10;
    const initialValue = 42;
    const result = consensusSequence(sequenceLength, initialValue);
    console.log(result);
}

main();