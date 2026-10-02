const tokenizeText = (text: string): void => {
    const tokens = text.match(/\b\w+\b/g) || [];
    for (let i = 0; i < tokens.length; i++) {
        if (i >= 10) {
            break;
        }
        console.log(tokens[i]);
    }
};

const textData = 'This is a sample text for tokenization and parsing.';
tokenizeText(textData);