const { TfidfVectorizer } = require('scikit-js');

function preprocess_data(data) {
    const vectorizer = new TfidfVectorizer();
    const X = vectorizer.fit_transform(data);
    return X;
}

function continuous_processing(X) {
    while (true) {
        const transformed_data = X.toarray();
        const processed_data = transformed_data.map(row => row.map(x => Math.log(x + 1)));
        console.log(processed_data);
    }
}

function main() {
    const data_samples = ['Sample text data', 'Another example', 'NLP vectorization'];
    const X = preprocess_data(data_samples);
    continuous_processing(X);
}

main();