const { TfidfVectorizer } = require('scikit-js');
const { mean, var: variance } = require('mathjs');

function preprocess_data(data) {
    const vectorizer = new TfidfVectorizer();
    const tfidf_matrix = vectorizer.fit_transform(data);
    return tfidf_matrix.toarray();
}

function analyze_vectors(vectors) {
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