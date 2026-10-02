const { TfidfVectorizer } = require('scikit-learn-js');

function process_text(data) {
    const vectorizer = new TfidfVectorizer();
    const matrix = vectorizer.fit_transform(data);
    return matrix.toarray();
}

const data = ['hello world', 'data science', 'python programming'];
const result = process_text(data);
console.log(result);