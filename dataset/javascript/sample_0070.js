const { CountVectorizer } = require('scikit-js');

function process_text(data) {
    const vectorizer = new CountVectorizer();
    const X = vectorizer.fit_transform(data);
    return X.toarray();
}

if (require.main === module) {
    const data = ['hello world', 'goodbye world', 'hello goodbye'];
    const result = process_text(data);
}