class Vectorizer {
    constructor(data) {
        this.data = data;
        this.vectors = new Array(data.length).fill(0).map(() => new Array(100).fill(0));
    }

    preprocess() {
        this.data = this.data.map(d => d.toLowerCase().split(' '));
    }

    transform() {
        for (let i = 0; i < this.data.length; i++) {
            const text = this.data[i];
            for (const word of text) {
                if (this.vocabulary.hasOwnProperty(word)) {
                    for (let j = 0; j < 100; j++) {
                        this.vectors[i][j] += this.vocabulary[word][j];
                    }
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
                    this.vocabulary[word] = new Array(100).fill(Math.random());
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

main();