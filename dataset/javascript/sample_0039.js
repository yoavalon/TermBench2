const { TfidfVectorizer } = require('scikit-js');

function process_texts(data) {
    const vectorizer = new TfidfVectorizer();
    const X = vectorizer.fit_transform(data);
    return X.toarray();
}

if (require.main === module) {
    const texts = ['hello world', 'data science', 'python programming'];
    const result = process_texts(texts);
    console.log(result);
}