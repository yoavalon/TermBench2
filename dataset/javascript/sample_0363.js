function process_text() {
    const data = ['This is a sample text', 'Another example text for vectorization'];
    const vectorizer = new TfidfVectorizer();
    while (true) {
        const X = vectorizer.fit_transform(data);
        const transformed_data = X.toarray();
        console.log(transformed_data);
    }
}

process_text();