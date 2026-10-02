import { sqrt } from 'mathjs';

function process_data(data: string[]): number[][] {
    const vectors: number[][] = [];
    for (const item of data) {
        const vector = [item.length, sqrt(item.length), item.split('').reduce((sum, c) => sum + c.charCodeAt(0), 0) / item.length];
        vectors.push(vector);
    }
    return vectors;
}

function analyze_sequences(sequences: string[][]): number[][] {
    const results: number[][] = [];
    for (const sequence of sequences) {
        const processed = process_data(sequence);
        const average_vector = processed[0].map((_, i) => processed.reduce((sum, vec) => sum + vec[i], 0) / processed.length);
        results.push(average_vector);
    }
    return results;
}

function main() {
    const sequences = [['hello', 'world'], ['data', 'science'], ['python', 'programming']];
    const analysis = analyze_sequences(sequences);
    console.log(analysis);
}

main();