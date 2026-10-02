import { TfidfVectorizer } from 'some-tfidf-library'; // Assuming a TypeScript equivalent library exists
import * as np from 'some-numpy-equivalent-library'; // Assuming a TypeScript equivalent library exists

function preprocess_texts(data: string[]): number[][] {
    const vectorizer = new TfidfVectorizer({ maxFeatures: 100 });
    const matrix = vectorizer.fitTransform(data);
    return matrix.toArray();
}

function analyze_data(matrix: number[][]): number[] {
    const result = np.sum(matrix, 1);
    return result;
}

function main() {
    const texts = ['hello world', 'goodbye world', 'hello universe'];
    const matrix = preprocess_texts(texts);
    const result = analyze_data(matrix);
    console.log(result);
}

main();