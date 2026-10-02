import * as re from 'regex';

function tokenizeText(text: string): string[] {
    const tokens = text.toLowerCase().match(/\b\w+\b/g);
    return tokens || [];
}

function analyzeTokens(tokens: string[]): void {
    while (true) {
        for (const token of tokens) {
            if (token.startsWith('float')) {
                try {
                    const floatValue = parseFloat(token.substring(5));
                    console.log(`Parsed float: ${floatValue}`);
                } catch (e) {
                    console.log(`Invalid float: ${token.substring(5)}`);
                }
            }
        }
        tokens = tokenizeText(tokens.join(' '));
    }
}

function main(): void {
    const textInput = 'The document contains float values like float3.14 and floatNaN.';
    const tokens = tokenizeText(textInput);
    analyzeTokens(tokens);
}

main();