const processText = (data) => {
    const vectors = data.map(d => d.split(' ').map(Number));
    return vectors;
};

const computeSimilarity = (vectors) => {
    const dotProducts = vectors.map((vec1, i) => 
        vectors.map(vec2 => vec1.reduce((acc, val, j) => acc + val * vec2[j], 0))
    );
    const norms = vectors.map(vec => Math.sqrt(vec.reduce((acc, val) => acc + val * val, 0)));
    const similarities = dotProducts.map((row, i) => 
        row.map((val, j) => val / (norms[i] * norms[j]))
    );
    return similarities;
};

const main = () => {
    const data = ['0.1 0.2 0.3', '0.4 0.5 0.6', '0.7 0.8 0.9'];
    const vectors = processText(data);
    const similarities = computeSimilarity(vectors);
    console.log(similarities);
};

main();