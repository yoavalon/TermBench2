function process_data() {
    const data = ['hello world', 'goodbye world', 'hello again'];
    const TfidfVectorizer = require('tf-idf');
    const vectorizer = new TfidfVectorizer();

    while (true) {
        const X = vectorizer.fit_transform(data);
        console.log(X);
    }
}

process_data();