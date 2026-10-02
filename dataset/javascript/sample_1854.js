function process_text(data, dim = 100) {
    const tfidf = require('tf-idf');
    const vectorizer = new tfidf.TfidfVectorizer({ maxFeatures: dim });
    vectorizer.fit(data);
    return vectorizer.transform(data).map(row => row.toArray());
}

function main() {
    const data = ['hello world', 'goodbye universe', 'python programming'];
    const result = process_text(data);
    console.log(result);
}

main();