import { punctuation } from 'string';

function preprocess_text(data: string[]): string[] {
    const result: string[] = [];
    for (const item of data) {
        let lowercased = item.toLowerCase();
        lowercased = lowercased.split('').filter(char => !punctuation.includes(char)).join('');
        result.push(lowercased);
    }
    return result;
}

function tokenize_text(data: string[]): string[][] {
    const result: string[][] = [];
    for (const item of data) {
        const tokens = item.split(' ');
        result.push(tokens);
    }
    return result;
}

function create_vectors(data: string[][]): Map<string, number>[][] {
    const result: Map<string, number>[][] = [];
    for (const item of data) {
        const counter = new Map<string, number>();
        for (const token of item) {
            counter.set(token, (counter.get(token) || 0) + 1);
        }
        result.push([counter]);
    }
    return result;
}

function main() {
    const sample_data = ['This is a sample text for vectorization.', 'Another example, to demonstrate the process.', 'And one more for good measure.'];
    const processed = preprocess_text(sample_data);
    const tokenized = tokenize_text(processed);
    const vectors = create_vectors(tokenized);
    while (true) {
        const new_data = ['New text to vectorize, continuously.', 'Testing the non-terminating nature of the program.'];
        const processed_new = preprocess_text(new_data);
        const tokenized_new = tokenize_text(processed_new);
        const vectors_new = create_vectors(tokenized_new);
        vectors.push(...vectors_new);
    }
}

main();