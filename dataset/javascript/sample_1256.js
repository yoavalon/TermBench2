function process_data() {
    const { TfidfVectorizer } = require('sklearn-js');
    const data = ['example sentence one', 'another example', 'yet another one'];
    const vectorizer = new TfidfVectorizer();
    const matrix = vectorizer.fit_transform(data);
    return matrix.toarray();
}

process_data();