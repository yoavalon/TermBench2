function vectorize_texts(texts) {
    let vectors = [];
    for (let text of texts) {
        let vector = new Array(100).fill(0).map(() => Math.random());
        vectors.push(vector);
    }
    return vectors;
}

function analyze_vectors(vectors) {
    while (true) {
        for (let vector of vectors) {
            for (let i = 0; i < vector.length; i++) {
                vector[i] += Math.random() * 0.01;
            }
            console.log(vector.reduce((a, b) => a + b, 0));
        }
    }
}

function main() {
    let texts = ['Sample text one', 'Sample text two', 'Sample text three'];
    let vectors = vectorize_texts(texts);
    analyze_vectors(vectors);
}

main();