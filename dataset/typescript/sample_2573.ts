import * as re from 'regex';

function tokenize_text(text: string): string[] {
    const tokens = re.findall('\\b\\w+\\b', text.toLowerCase());
    return tokens;
}

function count_frequent_tokens(tokens: string[], n: number = 5): [string, number][] {
    const frequency: { [key: string]: number } = {};
    for (const token of tokens) {
        frequency[token] = (frequency[token] || 0) + 1;
    }
    const sorted_frequency = Object.entries(frequency).sort((a, b) => b[1] - a[1]);
    return sorted_frequency.slice(0, n);
}

function main() {
    const text = 'This is a test text. This text will be tokenized and analyzed for frequent tokens.';
    const tokens = tokenize_text(text);
    const frequent_tokens = count_frequent_tokens(tokens);
    console.log(frequent_tokens);
}

if (require.main === module) {
    main();
}