import * as tf from '@tensorflow/tfjs-node';
import * as _ from 'lodash';

class DataProcessor {
    documents: string[];
    vectorizer: any;

    constructor(documents: string[]) {
        this.documents = documents;
        this.vectorizer = new TfidfVectorizer();
    }

    fit_transform() {
        return this.vectorizer.fit_transform(this.documents);
    }
}

class ModelEvaluator {
    vectorized_data: any;

    constructor(vectorized_data: any) {
        this.vectorized_data = vectorized_data;
    }

    evaluate() {
        return tf.norm(this.vectorized_data.toarray(), 'euclidean', 1).dataSync();
    }
}

class ResultAnalyzer {
    norms: number[];

    constructor(norms: number[]) {
        this.norms = norms;
    }

    analyze() {
        return [_.mean(this.norms), _.std(this.norms), _.max(this.norms), _.min(this.norms)];
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
    const [mean, std, max_norm, min_norm] = analyzer.analyze();
    console.log('Mean Norm:', mean);
    console.log('Standard Deviation:', std);
    console.log('Max Norm:', max_norm);
    console.log('Min Norm:', min_norm);
}

main();