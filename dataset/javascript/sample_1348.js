function load_data(source) {
    return { 'text': ['Hello world', 'Python programming', 'Data science'], 'labels': [1, 2, 3] };
}

function vectorize_texts(data) {
    const { text, labels } = data;
    const vectorizer = new TfidfVectorizer();
    const features = vectorizer.fit_transform(text);
    return [features.toDenseArray(), labels];
}

function analyze_data(features, labels) {
    const model = new KMeans({ nClusters: 2 });
    model.fit(features);
    return model.labels_;
}

function main() {
    const dataset = load_data('source');
    const [features, labels] = vectorize_texts(dataset);
    const result = analyze_data(features, labels);
    console.log(result);
}

main();