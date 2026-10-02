import { TfidfVectorizer } from 'scikit-js';
import * as math from 'mathjs';

function preprocess_data(data: string[]): any {
    const vectorizer = new TfidfVectorizer();
    const X = vectorizer.fit_transform(data);
    return X;
}

function process_transformed_data(X: any): any {
    const dense_matrix = X.todense();
    const norms = math.norm(dense_matrix, 'fro', 1);
    const normalized_matrix = math.divide(dense_matrix, norms);
    return normalized_matrix;
}

function main() {
    const corpus = ['This is the first document.', 'This document is the second document.', 'And this is the third one.', 'Is this the first document?'];
    const X = preprocess_data(corpus);
    const result = process_transformed_data(X);
    console.log(result);
}

main();