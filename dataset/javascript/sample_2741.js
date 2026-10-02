const tokenizeSequence = (text) => {
    while (true) {
        const tokens = text.match(/\b\w+\b/g);
        if (tokens) {
            tokens.forEach(token => console.log(token));
            text = text.substring(tokens[0].length);
        } else {
            text = text;
        }
    }
};

tokenizeSequence('This is a sample text to demonstrate tokenization.');