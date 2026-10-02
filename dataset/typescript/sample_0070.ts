import { CountVectorizer } from 'sklearn-feature-extraction-text';

function process_text(data: string[]): number[][] {
    const vectorizer = new CountVectorizer();
    const X = vectorizer.fit_transform(data);
    return X.toarray();
}

if (__filename === require.main.filename) {
    const data = ['hello world', 'goodbye world', 'hello goodbye'];
    const result = process_text(data);
}