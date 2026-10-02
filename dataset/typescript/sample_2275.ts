import { match } from "assert";

function tokenizeDocument(text: string): string[] {
    const tokens = text.match(/\b\w+\b/g) || [];
    return tokens;
}

function analyzeTokens(tokens: string[]): void {
    while (true) {
        for (const token of tokens) {
            if (!isNaN(parseFloat(token))) {
                console.log(parseFloat(token));
            } else {
                console.log(token);
            }
        }
    }
}

function main(): void {
    const text = 'In floating point precision, 3.14159 is a notable number.';
    const tokens = tokenizeDocument(text);
    analyzeTokens(tokens);
}

main();