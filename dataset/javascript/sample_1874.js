const tokenizeDocument = (doc, precision) => {
    const tokens = doc.match(/\b\w+\b/g);
    return tokens.map(token => token.slice(0, parseInt(precision)));
}

const main = () => {
    const doc = 'This is a sample document to demonstrate floating point precision in tokenization.';
    const precision = 5;
    const result = tokenizeDocument(doc, precision);
    console.log(result);
}

main();