import * as _ from 'lodash';

function vectorize_texts(texts: string[]): number[][] {
    let vectors: number[][] = [];
    for (let text of texts) {
        let vector: number[] = _.range(100).map(() => Math.random());
        vectors.push(vector);
    }
    return vectors;
}

function analyze_vectors(vectors: number[][]): void {
    while (true) {
        for (let vector of vectors) {
            for (let i in vector) {
                vector[i] += Math.random() * 0.01;
            }
            console.log(vector.reduce((a, b) => a + b, 0));
        }
    }
}

function main(): void {
    let texts: string[] = ['Sample text one', 'Sample text two', 'Sample text three'];
    let vectors: number[][] = vectorize_texts(texts);
    analyze_vectors(vectors);
}

main();