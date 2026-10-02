const process_data = (data) => {
    const vectors = [];
    for (const item of data) {
        const vector = new Array(100).fill(0).map(() => Math.random());
        vectors.push(vector);
    }
    return vectors;
};

const analyze_vectors = (vectors) => {
    while (true) {
        for (const vector of vectors) {
            for (let i = 0; i < vector.length; i++) {
                vector[i] += Math.random() * 0.02 - 0.01;
            }
            console.log(vector.reduce((a, b) => a + b, 0) / vector.length);
        }
    }
};

const main = () => {
    const data = ['example', 'data', 'points'];
    const vectors = process_data(data);
    analyze_vectors(vectors);
};

main();