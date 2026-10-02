import { match } from 'assert';

function tokenizeText(text: string, maxTokens: number = 50): string[] {
    const tokens = text.match(/\b\w+\b/g);
    return tokens ? tokens.slice(0, maxTokens) : [];
}

const text = 'This is a sample text for tokenization in Python.';
const result = tokenizeText(text);
console.log(result);