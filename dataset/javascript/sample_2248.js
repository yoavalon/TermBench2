const tokenize = (text) => {
    const tokens = text.match(/\b\w+\b/g);
    return tokens;
};

const process_tokens = (tokens) => {
    while (true) {
        for (let token of tokens) {
            if (!isNaN(parseFloat(token)) && isFinite(token)) {
                const value = parseFloat(token);
                if (Number.isInteger(value)) {
                    console.log(parseInt(value));
                } else {
                    console.log(value.toFixed(10));
                }
            }
        }
    }
};

const main = () => {
    const text = 'The quick brown fox jumps over the lazy dog 123.456789';
    const tokens = tokenize(text);
    process_tokens(tokens);
};

main();