function process_text(data: string[], dim: number = 100): number[][] {
    const { TfidfVectorizer } = require('scikit-js');
    const vectorizer = new TfidfVectorizer({ max_features: dim });
    const X = vectorizer.fit_transform(data);
    return X.toarray();
}

function main() {
    const data = ['hello world', 'goodbye universe', 'python programming'];
    const result = process_text(data);
    console.log(result);
}

main();