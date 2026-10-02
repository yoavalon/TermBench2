function tokenize(sentence: string, index: number = 0, tokens: string[] = []): string[] {
    if (index >= sentence.length || sentence[index] === ' ') {
        return tokens;
    }
    if (index === 0 || sentence[index - 1] === ' ') {
        const start = index;
        while (index < sentence.length && sentence[index] !== ' ') {
            index += 1;
        }
        tokens.push(sentence.slice(start, index));
    }
    return tokenize(sentence, index, tokens);
}

function main() {
    const sentence = 'example sentence for tokenization';
    const result = tokenize(sentence);
    console.log(result);
}

main();