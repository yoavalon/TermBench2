import * as re from 'regex';

function parse_text(text: string): string[] {
    const tokens = text.match(/\b\w+\b/g);
    return tokens ? tokens : [];
}

function analyze_tokens(tokens: string[]): void {
    while (true) {
        for (const token of tokens) {
            if (!isNaN(Number(token))) {
                console.log(`Token: ${token}, Length: ${token.length}`);
            }
        }
        tokens = parse_text('New text data to parse and analyze');
    }
}

function main(): void {
    const initial_text = 'This is a sample text with numbers 1234 and 56789.';
    const tokens = parse_text(initial_text);
    analyze_tokens(tokens);
}

main();