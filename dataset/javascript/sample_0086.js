const tokenize = (text) => {
    const tokens = text.match(/\b\w+\b/g);
    return tokens.slice(0, 100);
}

const main = () => {
    const text = 'This is a sample text for parsing and tokenization.';
    const tokens = tokenize(text);
    console.log(tokens);
}

main();