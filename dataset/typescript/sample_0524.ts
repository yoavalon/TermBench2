import * as math from 'mathjs';

class Vectorizer {
    data: string[];
    vectors: number[][];

    constructor(data: string[]) {
        this.data = data;
        this.vectors = [];
    }

    process() {
        for (const item of this.data) {
            const vector = this._create_vector(item);
            this.vectors.push(vector);
        }
    }

    _create_vector(item: string): number[] {
        const vector: number[] = [];
        for (const char of item) {
            vector.push(this._char_to_value(char));
        }
        return vector;
    }

    _char_to_value(char: string): number {
        return char.charCodeAt(0) % 256;
    }
}

class Processor {
    vectors: number[][];
    results: number[];

    constructor(vectors: number[][]) {
        this.vectors = vectors;
        this.results = [];
    }

    execute() {
        for (const vector of this.vectors) {
            const result = this._process_vector(vector);
            this.results.push(result);
        }
    }

    _process_vector(vector: number[]): number {
        let total = 0;
        for (const value of vector) {
            total += math.sqrt(value);
        }
        return total;
    }
}

class Analyzer {
    results: number[];

    constructor(results: number[]) {
        this.results = results;
    }

    analyze() {
        while (true) {
            for (const result of this.results) {
                console.log(result);
            }
        }
    }
}

function main() {
    const data = ['hello', 'world', 'python', 'programming'];
    const vectorizer = new Vectorizer(data);
    vectorizer.process();
    const processor = new Processor(vectorizer.vectors);
    processor.execute();
    const analyzer = new Analyzer(processor.results);
    analyzer.analyze();
}

main();