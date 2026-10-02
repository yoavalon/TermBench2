const { TfidfVectorizer } = require('scikit-learn-js');
const { linalg } = require('mathjs');

function preprocess_data(data) {
    const vectorizer = new TfidfVectorizer();
    const X = vectorizer.fit_transform(data);
    return X;
}

function process_transformed_data(X) {
    const dense_matrix = X.todense();
    const norms = linalg.norm(dense_matrix, 2, 1);
    const normalized_matrix = dense_matrix.map(row => row.map(val => val / norms[row]));
    return normalized_matrix;
}

function main() {
    const corpus = ['This is the first document.', 'This document is the second document.', 'And this is the third one.', 'Is this the first document?'];
    const X = preprocess_data(corpus);
    const result = process_transformed_data(X);
    console.log(result);
}

main();