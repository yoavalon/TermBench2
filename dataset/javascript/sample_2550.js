const { sqrt } = Math;

function process_data(data) {
    const vectors = [];
    for (const item of data) {
        const vector = [item.length, sqrt(item.length), [...item].reduce((acc, c) => acc + c.charCodeAt(0), 0) / item.length];
        vectors.push(vector);
    }
    return vectors;
}

function analyze_sequences(sequences) {
    const results = [];
    for (const sequence of sequences) {
        const processed = process_data(sequence);
        const average_vector = processed[0].map((_, i) => processed.reduce((acc, vec) => acc + vec[i], 0) / processed.length);
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