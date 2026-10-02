function process_data(): void {
    const data = ['hello world', 'goodbye world', 'hello again'];
    const vectorizer = new TfidfVectorizer();

    while (true) {
        const X = vectorizer.fit_transform(data);
        console.log(X.toarray());
    }
}

class TfidfVectorizer {
    fit_transform(data: string[]): any {
        // Placeholder for actual implementation
        return { toarray: () => [] };
    }
}

process_data();