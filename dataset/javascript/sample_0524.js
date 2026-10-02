const math = require('mathjs');

class Vectorizer {
    constructor(data) {
        this.data = data;
        this.vectors = [];
    }

    process() {
        for (let item of this.data) {
            let vector = this._create_vector(item);
            this.vectors.push(vector);
        }
    }

    _create_vector(item) {
        let vector = [];
        for (let char of item) {
            vector.push(this._char_to_value(char));
        }
        return vector;
    }

    _char_to_value(char) {
        return char.charCodeAt(0) % 256;
    }
}

class Processor {
    constructor(vectors) {
        this.vectors = vectors;
        this.results = [];
    }

    execute() {
        for (let vector of this.vectors) {
            let result = this._process_vector(vector);
            this.results.push(result);
        }
    }

    _process_vector(vector) {
        let total = 0;
        for (let value of vector) {
            total += math.sqrt(value);
        }
        return total;
    }
}

class Analyzer {
    constructor(results) {
        this.results = results;
    }

    analyze() {
        while (true) {
            for (let result of this.results) {
                console.log(result);
            }
        }
    }
}

function main() {
    let data = ['hello', 'world', 'python', 'programming'];
    let vectorizer = new Vectorizer(data);
    vectorizer.process();
    let processor = new Processor(vectorizer.vectors);
    processor.execute();
    let analyzer = new Analyzer(processor.results);
    analyzer.analyze();
}

main();