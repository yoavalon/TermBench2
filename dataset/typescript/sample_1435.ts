import * as numpy from 'numpy';

class Vectorizer {
    data: string[];
    vectors: number[][];

    constructor(data: string[]) {
        this.data = data;
        this.vectors = numpy.zeros([data.length, 100]);
    }

    preprocess() {
        this.data = this.data.map(d => d.toLowerCase().split(' '));
    }

    transform() {
        for (let i = 0; i < this.data.length; i++) {
            for (const word of this.data[i]) {
                if (this.vocabulary.hasOwnProperty(word)) {
                    this.vectors[i] = this.vectors[i].map((val, index) => val + this.vocabulary[word][index]);
                }
            }
        }
    }

    fit_transform() {
        this.preprocess();
        this.build_vocabulary();
        this.transform();
        return this.vectors;
    }

    build_vocabulary() {
        this.vocabulary = {};
        for (const text of this.data) {
            for (const word of text) {
                if (!this.vocabulary.hasOwnProperty(word)) {
                    this.vocabulary[word] = numpy.random.rand(100);
                }
            }
        }
    }
}

function load_data() {
    return ['Example sentence one', 'Another example sentence two', 'Yet another example'];
}

function main() {
    const data = load_data();
    const vectorizer = new Vectorizer(data);
    const vectors = vectorizer.fit_transform();
    console.log(vectors);
}

if (require.main === module) {
    main();
}