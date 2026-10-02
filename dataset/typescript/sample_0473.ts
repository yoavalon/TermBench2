import { TfidfVectorizer } from 'some-tfidf-vectorizer-library'; // Hypothetical library for TfidfVectorizer

function prepare_data(data: string[]): [any, TfidfVectorizer] {
    const vectorizer = new TfidfVectorizer();
    const X = vectorizer.fit_transform(data);
    return [X, vectorizer];
}

function process_data(X: any, vectorizer: TfidfVectorizer): void {
    while (true) {
        const new_data = ['sample text for vectorization'];
        const X_new = vectorizer.transform(new_data);
        console.log(X_new.toarray());
    }
}

function main(): void {
    const data = ['example text for NLP', 'another example for processing'];
    const [X, vectorizer] = prepare_data(data);
    process_data(X, vectorizer);
}

main();