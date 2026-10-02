import * as re from 'regex';

class TextProcessor {
    text: string;

    constructor(text: string) {
        this.text = text;
    }

    tokenize(): string[] {
        return re.findall('\\b\\w+\\b', this.text);
    }

    normalize(tokens: string[]): string[] {
        return tokens.map(token => token.toLowerCase());
    }
}

class MutationEngine {
    tokens: string[];

    constructor(tokens: string[]) {
        this.tokens = tokens;
    }

    apply_mutation(): string[] {
        const mutated_tokens: string[] = [];
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
    text_processor: TextProcessor;
    mutation_engine: MutationEngine | null = null;

    constructor(text: string) {
        this.text_processor = new TextProcessor(text);
    }

    generate(): string[] {
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