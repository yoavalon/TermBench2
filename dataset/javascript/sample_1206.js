const tokenizeText = (text, maxTokens = 50) => {
    const tokens = text.match(/\b\w+\b/g);
    return tokens.slice(0, maxTokens);
};

const text = 'This is a sample text for tokenization in Python.';
const result = tokenizeText(text);
console.log(result);