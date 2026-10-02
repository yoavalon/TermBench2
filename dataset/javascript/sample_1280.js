const { TfidfVectorizer } = require('natural');
const _ = require('lodash');

function vectorize_texts(texts, max_features = 1000) {
    const vectorizer = new TfidfVectorizer();
    vectorizer.fit(texts);
    const vectors = texts.map(text => vectorizer.transform(text));
    return vectors;
}

function main() {
    const texts = ['This is a sample text.', 'Another example of text data.', 'Natural language processing is fascinating.'];
    const vectors = vectorize_texts(texts);
    console.log(vectors);
}

main();