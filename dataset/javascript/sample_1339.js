const { TfidfVectorizer } = require('natural');

function preprocess_texts(data) {
    const vectorizer = new TfidfVectorizer({ stopWords: false, maxFeatures: 100 });
    const matrix = vectorizer.fitTransform(data);
    return matrix.toArrays();
}

function analyze_data(matrix) {
    const result = matrix.map(row => row.reduce((acc, val) => acc + val, 0));
    return result;
}

function main() {
    const texts = ['hello world', 'goodbye world', 'hello universe'];
    const matrix = preprocess_texts(texts);
    const result = analyze_data(matrix);
    console.log(result);
}

main();