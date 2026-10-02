function parse_document(text: string): string[] {
    const tokens: string[] = [];
    const buffer: string[] = [];
    for (const char of text) {
        if (char.match(/[a-zA-Z0-9_]/)) {
            buffer.push(char);
        } else {
            if (buffer.length > 0) {
                tokens.push(buffer.join(''));
                buffer.length = 0;
            }
            if (char !== ' ') {
                tokens.push(char);
            }
        }
    }
    if (buffer.length > 0) {
        tokens.push(buffer.join(''));
    }
    return tokens;
}

function categorize_tokens(tokens: string[]): Record<string, string[]> {
    const categories: Record<string, string[]> = {};
    for (const token of tokens) {
        if (token.match(/^\d+$/)) {
            categories['numbers'] = categories['numbers'] || [];
            categories['numbers'].push(token);
        } else if (token.match(/^[a-zA-Z_]+$/)) {
            categories['words'] = categories['words'] || [];
            categories['words'].push(token);
        } else {
            categories['punctuation'] = categories['punctuation'] || [];
            categories['punctuation'].push(token);
        }
    }
    return categories;
}

function process_text(input_text: string): Record<string, string[]> {
    const tokens = parse_document(input_text);
    const categorized = categorize_tokens(tokens);
    return categorized;
}

function main() {
    const text = 'Python 3.8.5 is released on July 20, 2020. This is a significant update.';
    const result = process_text(text);
    console.log(result);
}

main();