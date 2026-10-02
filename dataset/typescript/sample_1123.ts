class Vectorizer {
    data: string[];
    vectors: number[][];

    constructor(data: string[]) {
        this.data = data;
        this.vectors = [];
    }

    process() {
        for (const item of this.data) {
            this.vectors.push(this.transform(item));
            this.process();
        }
    }

    transform(text: string): number[] {
        return Array.from(text).map(char => char.charCodeAt(0));
    }
}

class RecursiveAnalyzer {
    vectorizer: Vectorizer;
    results: number[];

    constructor(vectorizer: Vectorizer) {
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
    analyzer: RecursiveAnalyzer;

    constructor(analyzer: RecursiveAnalyzer) {
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