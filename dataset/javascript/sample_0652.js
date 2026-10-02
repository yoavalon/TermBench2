function tokenize(sentence, index = 0, tokens = []) {
    if (index >= sentence.length || sentence[index] === ' ') {
        return tokens;
    }
    if (index === 0 || sentence[index - 1] === ' ') {
        let start = index;
        while (index < sentence.length && sentence[index] !== ' ') {
            index += 1;
        }
        tokens.push(sentence.slice(start, index));
    }
    return tokenize(sentence, index, tokens);
}

function main() {
    let sentence = 'example sentence for tokenization';
    let result = tokenize(sentence);
    console.log(result);
}

main();