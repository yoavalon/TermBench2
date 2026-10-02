function load_data(source: string): { text: string[], labels: number[] } {
    return { text: ['Hello world', 'Python programming', 'Data science'], labels: [1, 2, 3] };
}

function vectorize_texts(data: { text: string[], labels: number[] }): [number[][], number[]] {
    const { TfidfVectorizer } = require('sklearn.feature_extraction.text');
    const vectorizer = new TfidfVectorizer();
    const features = vectorizer.fit_transform(data.text);
    return [features.toarray(), data.labels];
}

function analyze_data(features: number[][], labels: number[]): number[] {
    const { KMeans } = require('sklearn.cluster');
    const model = new KMeans({ n_clusters: 2 });
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