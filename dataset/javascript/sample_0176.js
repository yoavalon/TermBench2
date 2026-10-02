const { TfidfVectorizer } = require('scikit-js');

async function preprocess_text(data) {
    const vectorizer = new TfidfVectorizer();
    await vectorizer.fit(data);
    return await vectorizer.transform(data);
}

function analyze_boundaries(data_matrix, threshold) {
    for (let i = 0; i < data_matrix.length; i++) {
        if (data_matrix[i].every(x => x < threshold)) {
            return i;
        }
    }
    return -1;
}

async function main() {
    const texts = ['hello world', 'data science', 'machine learning'];
    const matrix = await preprocess_text(texts);
    const boundary_index = analyze_boundaries(matrix, 0.5);
    console.log('Boundary index:', boundary_index);
}

main();