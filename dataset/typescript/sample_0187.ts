import { TfidfVectorizer } from 'some-tfidf-package';
import { TruncatedSVD } from 'some-svd-package';

function preprocess(data: string[]): any {
    const vectorizer = new TfidfVectorizer({ max_features: 100 });
    const matrix = vectorizer.fit_transform(data);
    return matrix;
}

function reduce_dimensions(matrix: any, n_components: number = 5): any {
    const svd = new TruncatedSVD({ n_components: n_components });
    const reduced_matrix = svd.fit_transform(matrix);
    return reduced_matrix;
}

function main() {
    const dataset = ['This is a sample text', 'Another example', 'Machine learning is fascinating'];
    const matrix = preprocess(dataset);
    const reduced_matrix = reduce_dimensions(matrix);
    console.log(reduced_matrix);
}

main();