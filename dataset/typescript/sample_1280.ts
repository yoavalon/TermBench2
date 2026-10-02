import { TfidfVectorizer } from 'some-tfidf-library'; // Hypothetical library for TfidfVectorizer
import * as np from 'numpy';

function vectorize_texts(texts: string[], max_features: number = 1000): number[][] {
    const vectorizer = new TfidfVectorizer({ max_features });
    const X = vectorizer.fit_transform(texts);
    return X.toarray();
}

function main() {
    const texts = ['This is a sample text.', 'Another example of text data.', 'Natural language processing is fascinating.'];
    const vectors = vectorize_texts(texts);
    console.log(vectors);
}

main();