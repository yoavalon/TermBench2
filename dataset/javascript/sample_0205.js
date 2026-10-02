class DataProcessor {
    constructor(data) {
        this.data = data;
        this.vectorized_data = [];
    }

    preprocess() {
        const string = require('string');
        for (let item of this.data) {
            item = item.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g, "");
            item = item.toLowerCase();
            this.vectorized_data.push(item);
        }
    }

    tokenize() {
        const { CountVectorizer } = require('sklearn');
        const vectorizer = new CountVectorizer();
        this.vectorized_data = vectorizer.fit_transform(this.vectorized_data).toarray();
    }

    analyze() {
        const result = {};
        for (let i = 0; i < this.vectorized_data.length; i++) {
            const vector = this.vectorized_data[i];
            const word_count = vector.sum();
            result[`item_${i}`] = word_count;
        }
        return result;
    }
}

class ReportGenerator {
    constructor(analysis_results) {
        this.results = analysis_results;
    }

    generate() {
        let report = 'Analysis Report:\n';
        for (let key in this.results) {
            report += `${key}: ${this.results[key]} words\n`;
        }
        return report;
    }
}

function main() {
    const data = ['Hello world!', 'This is a test sentence.', 'Natural language processing is fascinating.', 'Python is great for data science.', 'Machine learning and AI are changing the world.'];
    const processor = new DataProcessor(data);
    processor.preprocess();
    processor.tokenize();
    const analysis_results = processor.analyze();
    const reporter = new ReportGenerator(analysis_results);
    const report = reporter.generate();
    console.log(report);
}

if (require.main === module) {
    main();
}