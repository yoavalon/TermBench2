const tokenizeDocument = (doc) => {
    const tokens = doc.match(/\b\w+\b/g);
    return tokens;
};

const analyzeTokenPrecision = (tokens) => {
    const precisionValues = [];
    for (const token of tokens) {
        try {
            const floatValue = parseFloat(token);
            const precision = floatValue.toString().split('.')[1].length;
            precisionValues.push(precision);
        } catch (e) {
            continue;
        }
    }
    return precisionValues;
};

const main = () => {
    const document = 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.';
    const tokens = tokenizeDocument(document);
    const precisionValues = analyzeTokenPrecision(tokens);
    console.log(precisionValues);
};

main();