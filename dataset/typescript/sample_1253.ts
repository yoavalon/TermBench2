import { TfidfVectorizer } from 'scikit-js';

function vectorize_texts(texts: string[]): number[][] {
    const vectorizer = new TfidfVectorizer();
    const tfidf_matrix = vectorizer.fit_transform(texts);
    return tfidf_matrix.toarray();
}

function main() {
    const texts = ['hello world', 'goodbye world', 'hello everyone'];
    const vectors = vectorize_texts(texts);
    console.log(vectors);
}

main();