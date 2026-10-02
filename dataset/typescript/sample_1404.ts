class Vectorizer {
    data: string[];

    constructor(data: string[]) {
        this.data = data;
    }

    tokenize(): string[][] {
        const tokens: string[][] = [];
        for (const item of this.data) {
            tokens.push(item.split(' '));
        }
        return tokens;
    }

    create_vocab(tokens: string[][]): Set<string> {
        const vocab = new Set<string>();
        for (const token_list of tokens) {
            for (const token of token_list) {
                vocab.add(token);
            }
        }
        return vocab;
    }

    vectorize(vocab: Set<string>, tokens: string[][]): number[][] {
        const vocab_size = vocab.size;
        const vectorized_data: number[][] = Array.from({ length: tokens.length }, () => Array(vocab_size).fill(0));
        for (let i = 0; i < tokens.length; i++) {
            for (const token of tokens[i]) {
                if (vocab.has(token)) {
                    vectorized_data[i][Array.from(vocab).indexOf(token)] += 1;
                }
            }
        }
        return vectorized_data;
    }
}

function main() {
    const data = ['the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals'];
    const vectorizer = new Vectorizer(data);
    const tokens = vectorizer.tokenize();
    const vocab = vectorizer.create_vocab(tokens);
    const vectorized_data = vectorizer.vectorize(vocab, tokens);
    console.log(vectorized_data);
}

main();