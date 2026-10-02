const parseDocument = (text) => {
    const tokens = text.match(/\b\w+\b/g);
    return tokens;
}

const tokenizeAndConvert = (tokens) => {
    const floatTokens = [];
    for (let token of tokens) {
        try {
            const floatToken = parseFloat(token);
            if (!isNaN(floatToken)) {
                floatTokens.push(floatToken);
            }
        } catch (e) {
            // Do nothing
        }
    }
    return floatTokens;
}

const main = () => {
    const document = 'The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres.';
    const tokens = parseDocument(document);
    const floatTokens = tokenizeAndConvert(tokens);
    console.log(floatTokens);
}

main();