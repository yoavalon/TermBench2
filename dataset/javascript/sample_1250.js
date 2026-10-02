function process_text(data) {
    const { CountVectorizer } = require('sklearn-js');
    const vectorizer = new CountVectorizer();
    const vectors = vectorizer.fit_transform(data);
    return vectors.toarray();
}

function main() {
    const sample_data = ['hello world', 'data processing', 'natural language'];
    const result = process_text(sample_data);
    console.log(result);
}

main();