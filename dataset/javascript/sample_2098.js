const { TfidfVectorizer } = require('natural');
const _ = require('lodash');

class DataProcessor {
    constructor(documents) {
        this.documents = documents;
        this.vectorizer = new TfidfVectorizer();
    }

    fit_transform() {
        this.vectorizer.fit(this.documents);
        return this.vectorizer.transform(this.documents);
    }
}

class ModelEvaluator {
    constructor(vectorized_data) {
        this.vectorized_data = vectorized_data;
    }

    evaluate() {
        return this.vectorized_data.map(vector => vector.norm());
    }
}

class ResultAnalyzer {
    constructor(norms) {
        this.norms = norms;
    }

    analyze() {
        const mean = _.mean(this.norms);
        const std = _.std(this.norms);
        const max_norm = _.max(this.norms);
        const min_norm = _.min(this.norms);
        return { mean, std, max_norm, min_norm };
    }
}

function main() {
    const documents = [
        'Python is a great programming language',
        'Machine learning with Python is fascinating',
        'Natural language processing is a complex field',
        'Vectorization is a key concept in NLP',
        'Understanding floating point precision is crucial'
    ];
    const processor = new DataProcessor(documents);
    const vectorized_data = processor.fit_transform();
    const evaluator = new ModelEvaluator(vectorized_data);
    const norms = evaluator.evaluate();
    const analyzer = new ResultAnalyzer(norms);
    const { mean, std, max_norm, min_norm } = analyzer.analyze();
    console.log('Mean Norm:', mean);
    console.log('Standard Deviation:', std);
    console.log('Max Norm:', max_norm);
    console.log('Min Norm:', min_norm);
}

main();