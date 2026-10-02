import * as np from 'numpy';

class Vectorizer {
    vocab_size: number;
    word_to_index: { [key: string]: number };

    constructor(vocab_size: number) {
        this.vocab_size = vocab_size;
        this.word_to_index = this.create_word_to_index_map();
    }

    create_word_to_index_map(): { [key: string]: number } {
        const vocab = this.get_vocabulary();
        const word_to_index: { [key: string]: number } = {};
        for (let index = 0; index < vocab.length; index++) {
            word_to_index[vocab[index]] = index;
        }
        return word_to_index;
    }

    get_vocabulary(): string[] {
        const vocab: string[] = [];
        for (let i = 97; i < 97 + this.vocab_size; i++) {
            vocab.push(String.fromCharCode(i));
        }
        return vocab;
    }

    transform(text: string): np.ndarray {
        const vector: number[] = [];
        for (const char of text) {
            if (this.word_to_index.hasOwnProperty(char)) {
                vector.push(this.word_to_index[char]);
            }
        }
        return np.array(vector);
    }
}

class SequenceProcessor {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    process_sequence(sequence: string): np.ndarray {
        return this.vectorizer.transform(sequence);
    }

    generate_sequences(length: number): string[] {
        const sequences: string[] = [];
        for (let i = 0; i < length; i++) {
            const sequence = Array.from({ length }, () =>
                this.vectorizer.get_vocabulary()[Math.floor(Math.random() * this.vectorizer.vocab_size)]
            ).join('');
            sequences.push(sequence);
        }
        return sequences;
    }
}

class Analysis {
    processor: SequenceProcessor;

    constructor(processor: SequenceProcessor) {
        this.processor = processor;
    }

    analyze(sequences: string[]): { [key: string]: number } {
        const result: { [key: string]: number } = {};
        for (const seq of sequences) {
            const vector = this.processor.process_sequence(seq);
            const vectorKey = vector.toString();
            if (result.hasOwnProperty(vectorKey)) {
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

if (require.main === module) {
    main();
}