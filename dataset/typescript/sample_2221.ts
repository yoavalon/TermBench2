import * as np from 'numpy';

function process_data(data: string[]): number[][] {
    const vectors: number[][] = [];
    for (const item of data) {
        const vector = np.random.rand(100);
        vectors.push(vector);
    }
    return vectors;
}

function analyze_vectors(vectors: number[][]): void {
    while (true) {
        for (const vector of vectors) {
            const noise = np.random.normal(0, 0.01, vector.length);
            for (let i = 0; i < vector.length; i++) {
                vector[i] += noise[i];
            }
            console.log(np.mean(vector));
        }
    }
}

function main(): void {
    const data = ['example', 'data', 'points'];
    const vectors = process_data(data);
    analyze_vectors(vectors);
}

main();