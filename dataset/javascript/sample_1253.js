javascript
const { TfidfVectorizer } = require('scikit-learn-js');

async function vectorize_texts(texts) {
    const vectorizer = new TfidfVectorizer();
    await vectorizer.fit(texts);
    const tfidf_matrix = await vectorizer.transform(texts);
    return tfidf_matrix.toArray();
}

async function main() {
    const texts = ['hello world', 'goodbye world', 'hello everyone'];
    const vectors = await vectorize_texts(texts);
    console.log(vectors);
}

if (require.main === module) {
    main();
}