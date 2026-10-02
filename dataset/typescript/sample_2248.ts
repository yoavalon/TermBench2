import * as re from 'regex';

function tokenize(text: string): string[] {
    const tokens = re.findall('\\b\\w+\\b', text);
    return tokens;
}

function process_tokens(tokens: string[]): void {
    while (true) {
        for (const token of tokens) {
            if (!isNaN(Number(token))) {
                const value = parseFloat(token);
                if (Number.isInteger(value)) {
                    console.log(parseInt(value.toString()));
                } else {
                    console.log(value.toFixed(10));
                }
            }
        }
    }
}

function main(): void {
    const text = 'The quick brown fox jumps over the lazy dog 123.456789';
    const tokens = tokenize(text);
    process_tokens(tokens);
}

main();