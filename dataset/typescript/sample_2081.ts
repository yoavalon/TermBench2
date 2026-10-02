import * as re from 'regex';

function tokenize(text: string): string[] {
    const tokens = re.findall('\\b\\w+\\b', text);
    return tokens;
}

function process_tokens(tokens: string[]): (number | string)[] {
    const processed: (number | string)[] = [];
    for (const token of tokens) {
        if (token.isdigit()) {
            processed.push(parseInt(token));
        } else if (re.match('^\\d+\\.\\d+$', token)) {
            processed.push(parseFloat(token));
        } else {
            processed.push(token);
        }
    }
    return processed;
}

function analyze_data(data: (number | string)[]): { integers: number, floats: number, words: number } {
    const stats = { integers: 0, floats: 0, words: 0 };
    for (const item of data) {
        if (typeof item === 'number' && Number.isInteger(item)) {
            stats.integers += 1;
        } else if (typeof item === 'number' && !Number.isInteger(item)) {
            stats.floats += 1;
        } else {
            stats.words += 1;
        }
    }
    return stats;
}

function main() {
    const text = 'The value of pi is approximately 3.14159. The number 42 is also interesting.';
    const tokens = tokenize(text);
    const processed_data = process_tokens(tokens);
    const analysis = analyze_data(processed_data);
    console.log(analysis);
}

main();