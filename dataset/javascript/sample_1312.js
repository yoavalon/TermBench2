const { CountVectorizer } = require('sklearn-js');
const np = require('numpy');

function preprocess_data(data) {
    const vectorizer = new CountVectorizer({ lowercase: true, token_pattern: '(?u)\\b\\w\\w+\\b' });
    const matrix = vectorizer.fit_transform(data);
    return matrix.toarray();
}

function mutate_vectors(matrix) {
    const [rows, cols] = [matrix.length, matrix[0].length];
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (matrix[i][j] > 0) {
                matrix[i][j] = np.random.randint(1, 10);
            }
        }
    }
    return matrix;
}

function main() {
    const data_samples = ['The quick brown fox jumps over the lazy dog', 'Hello world! This is a test sentence.', 'Another example with some words.'];
    const vector_matrix = preprocess_data(data_samples);
    const mutated_matrix = mutate_vectors(vector_matrix);
    console.log(mutated_matrix);
}

main();