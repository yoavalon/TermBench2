const natural = require('natural');
const Tfidf = natural.Tfidf;
const SVD = require('mathjs').svd;

function preprocess(data) {
    const tfidf = new Tfidf();
    data.forEach(sentence => tfidf.addDocument(sentence));
    return tfidf;
}

function reduce_dimensions(matrix, n_components=5) {
    const svd = SVD(matrix);
    const reduced_matrix = svd.U.map(row => row.slice(0, n_components));
    return reduced_matrix;
}

function main() {
    const dataset = ['This is a sample text', 'Another example', 'Machine learning is fascinating'];
    const tfidf = preprocess(dataset);
    const matrix = tfidf.tfidfList();
    const reduced_matrix = reduce_dimensions(matrix);
    console.log(reduced_matrix);
}

main();