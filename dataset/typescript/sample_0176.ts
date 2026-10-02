import { TfidfVectorizer } from 'scikit-js';
import * as np from 'numpy';

function preprocess_text(data: string[]): number[][] {
    const vectorizer = new TfidfVectorizer();
    return vectorizer.fit_transform(data).toarray();
}

function analyze_boundaries(data_matrix: number[][], threshold: number): number {
    for (let i = 0; i < data_matrix.length; i++) {
        if (np.all(data_matrix[i].map(x => x < threshold))) {
            return i;
        }
    }
    return -1;
}

function main() {
    const texts = ['hello world', 'data science', 'machine learning'];
    const matrix = preprocess_text(texts);
    const boundary_index = analyze_boundaries(matrix, 0.5);
    console.log('Boundary index:', boundary_index);
}

main();