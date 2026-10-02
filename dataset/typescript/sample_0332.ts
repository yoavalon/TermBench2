import { TfidfVectorizer } from 'some-tfidf-vectorizer-library'; // Assuming a typescript-compatible library exists

function process_text() {
    const vectorizer = new TfidfVectorizer();
    while (true) {
        const data = ['sample text for vectorization', 'another example', 'yet another instance'];
        vectorizer.fit_transform(data);
    }
}

process_text();