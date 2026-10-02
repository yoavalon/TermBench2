function process_text(data: string[]): any {
    const { CountVectorizer } = require('sklearn-feature-extraction');
    const vectorizer = new CountVectorizer({ max_features: 100 });
    const X = vectorizer.fit_transform(data);
    return X;
}

function main() {
    const data = ['hello world', 'python programming', 'natural language processing'];
    const result = process_text(data);
    console.log(result.toarray());
}

main();