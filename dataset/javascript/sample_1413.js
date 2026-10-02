const re = require('regex');

class TextProcessor {
    constructor(text) {
        this.text = text;
    }

    tokenize() {
        return this.text.match(/\b\w+\b/g);
    }

    normalize(tokens) {
        return tokens.map(token => token.toLowerCase());
    }
}

class MutationEngine {
    constructor(tokens) {
        this.tokens = tokens;
    }

    apply_mutation() {
        const mutated_tokens = [];
        for (const token of this.tokens) {
            if (token.length > 3) {
                const mutated_token = token[0] + token[token.length - 1] + token.slice(1, -1).split('').reverse().join('');
                mutated_tokens.push(mutated_token);
            } else {
                const mutated_token = token.split('').reverse().join('');
                mutated_tokens.push(mutated_token);
            }
        }
        return mutated_tokens;
    }
}

class DatasetGenerator {
    constructor(text) {
        this.text_processor = new TextProcessor(text);
        this.mutation_engine = null;
    }

    generate() {
        const tokens = this.text_processor.tokenize();
        const normalized_tokens = this.text_processor.normalize(tokens);
        this.mutation_engine = new MutationEngine(normalized_tokens);
        const mutated_tokens = this.mutation_engine.apply_mutation();
        return mutated_tokens;
    }
}

function main() {
    const sample_text = 'The quick brown fox jumps over the lazy dog';
    const dataset_generator = new DatasetGenerator(sample_text);
    const result = dataset_generator.generate();
    console.log(result);
}

main();