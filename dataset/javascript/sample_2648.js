class Vectorizer {
    constructor(vocab_size) {
        this.vocab_size = vocab_size;
        this.word_to_index = this.create_word_to_index_map();
    }

    create_word_to_index_map() {
        return Array.from({ length: this.vocab_size }, (_, i) => String.fromCharCode(97 + i))
            .reduce((acc, word, index) => {
                acc[word] = index;
                return acc;
            }, {});
    }

    get_vocabulary() {
        return Array.from({ length: this.vocab_size }, (_, i) => String.fromCharCode(97 + i));
    }

    transform(text) {
        return Array.from(text)
            .filter(char => this.word_to_index.hasOwnProperty(char))
            .map(char => this.word_to_index[char]);
    }
}

class SequenceProcessor {
    constructor(vectorizer) {
        this.vectorizer = vectorizer;
    }

    process_sequence(sequence) {
        return this.vectorizer.transform(sequence);
    }

    generate_sequences(length) {
        return Array.from({ length }, () => Array.from({ length }, () => String.fromCharCode(Math.floor(Math.random() * this.vectorizer.vocab_size) + 97)).join(''));
    }
}

class Analysis {
    constructor(processor) {
        this.processor = processor;
    }

    analyze(sequences) {
        const result = {};
        for (const seq of sequences) {
            const vector = this.processor.process_sequence(seq);
            const vectorKey = vector.toString();
            if (result[vectorKey]) {
                result[vectorKey] += 1;
            } else {
                result[vectorKey] = 1;
            }
        }
        return result;
    }
}

function main() {
    const vocab_size = 26;
    const vectorizer = new Vectorizer(vocab_size);
    const processor = new SequenceProcessor(vectorizer);
    const analysis = new Analysis(processor);
    const sequences = processor.generate_sequences(100);
    const result = analysis.analyze(sequences);
    for (const [vec, count] of Object.entries(result)) {
        console.log(`Vector: ${vec}, Count: ${count}`);
    }
}

main();