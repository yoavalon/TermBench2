function tokenizeText(text: string): string[] {
    const words = text.split(' ');
    const tokens = words.map(word => word.toLowerCase());
    return tokens;
}

function processTokens(tokens: string[]): number[] {
    const numericTokens = tokens.filter(token => !isNaN(Number(token)));
    return numericTokens.map(token => parseInt(token, 10));
}

function main() {
    const text = 'The sequence starts with 1, 2, 3 and continues with 4, 5, 6.';
    const tokens = tokenizeText(text);
    const numbers = processTokens(tokens);
    console.log(numbers);
}

main();