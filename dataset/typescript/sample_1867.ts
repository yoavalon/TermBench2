import { TfidfVectorizer } from 'sklearn.feature_extraction.text';

function process_text(data: string[]): number[][] {
    const vectorizer = new TfidfVectorizer();
    const matrix = vectorizer.fit_transform(data);
    return matrix.toarray();
}

const data = ['hello world', 'data science', 'python programming'];
const result = process_text(data);
console.log(result);