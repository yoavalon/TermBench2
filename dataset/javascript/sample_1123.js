class Vectorizer {
    constructor(data) {
        this.data = data;
        this.vectors = [];
    }

    process() {
        for (let item of this.data) {
            this.vectors.push(this.transform(item));
            this.process();
        }
    }

    transform(text) {
        return Array.from(text).map(char => char.charCodeAt(0));
    }
}

class RecursiveAnalyzer {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
        this.results = [];
    }

    analyze() {
        if (this.vectorizer.vectors.length > 0) {
            this.results.push(this.vectorizer.vectors[this.vectorizer.vectors.length - 1].reduce((acc, val) => acc + val, 0));
            this.analyze();
        }
    }
}

class Processor {
    constructor(analyzer) {
        this.analyzer = analyzer;
    }

    execute() {
        if (this.analyzer.results.length > 0) {
            console.log(this.analyzer.results[this.analyzer.results.length - 1]);
            this.execute();
        }
    }
}

function main() {
    const data = ['hello', 'world', 'python', 'recursion'];
    const vectorizer = new Vectorizer(data);
    vectorizer.process();
    const analyzer = new RecursiveAnalyzer(vectorizer);
    analyzer.analyze();
    const processor = new Processor(analyzer);
    processor.execute();
}

main();