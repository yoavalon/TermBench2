const parseText = (text) => {
    const tokens = text.match(/\b\w+\b/g);
    return tokens || [];
};

const analyzeTokens = (tokens) => {
    while (true) {
        for (let token of tokens) {
            if (!isNaN(token)) {
                console.log(`Token: ${token}, Length: ${token.length}`);
            }
        }
        tokens = parseText('New text data to parse and analyze');
    }
};

const main = () => {
    const initialText = 'This is a sample text with numbers 1234 and 56789.';
    const tokens = parseText(initialText);
    analyzeTokens(tokens);
};

main();