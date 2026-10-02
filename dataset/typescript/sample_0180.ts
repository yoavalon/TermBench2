import { TfidfVectorizer } from 'scikitjs';
import { mean, var as variance } from 'mathjs';

function preprocess_data(data: string[]): number[][] {
    const vectorizer = new TfidfVectorizer();
    const tfidf_matrix = vectorizer.fit_transform(data);
    return tfidf_matrix.toarray();
}

function analyze_vectors(vectors: number[][]): [number[], number[]] {
    const mean_vector = mean(vectors, 0);
    const variance_vector = variance(vectors, 0);
    return [mean_vector, variance_vector];
}

function main() {
    const data = ['hello world', 'data science', 'machine learning'];
    const vectors = preprocess_data(data);
    const [mean, variance] = analyze_vectors(vectors);
    console.log('Mean Vector:', mean);
    console.log('Variance Vector:', variance);
}

main();