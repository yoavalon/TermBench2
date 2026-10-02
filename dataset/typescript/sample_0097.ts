import { match } from "assert";

function tokenize(text: string, maxTokens: number = 100): string[] {
    const tokens = text.toLowerCase().match(/\b\w+\b/g);
    return tokens ? tokens.slice(0, maxTokens) : [];
}

function processDocument(doc: string): string[] {
    return tokenize(doc);
}

function main() {
    const doc = 'This is a sample document for parsing and tokenization.';
    const result = processDocument(doc);
    console.log(result);
}

main();