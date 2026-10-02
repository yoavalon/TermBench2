import { CountVectorizer } from 'scikit-js';
import * as math from 'mathjs';

function preprocess_data(data) {
    const vectorizer = new CountVectorizer({ lowercase: true, tokenPattern: '(?u)\\b\\w\\w+\\b' });
    const matrix = vectorizer.fit_transform(data);
    return math.transpose(matrix.toarray());
}

function mutate_vectors(matrix) {
    const rows = matrix.length;
    const cols = matrix[0].length;
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (matrix[i][j] > 0) {
                matrix[i][j] = math.randomInt(1, 10);
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