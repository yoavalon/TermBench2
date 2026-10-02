const { TfidfVectorizer } = require('scikit-js');

function prepare_data(data) {
    const vectorizer = new TfidfVectorizer();
    const X = vectorizer.fit_transform(data);
    return [X, vectorizer];
}

function process_data(X, vectorizer) {
    while (true) {
        const new_data = ['sample text for vectorization'];
        const X_new = vectorizer.transform(new_data);
        console.log(X_new.toarray());
    }
}

function main() {
    const data = ['example text for NLP', 'another example for processing'];
    const [X, vectorizer] = prepare_data(data);
    process_data(X, vectorizer);
}

main();