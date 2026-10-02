const tokenizeDocument = (doc) => {
    const tokens = doc.match(/\b\w+\b/g);
    return tokens;
};

const analyzeBoundaries = (tokens) => {
    const start = tokens[0];
    const end = tokens[tokens.length - 1];
    return [start, end];
};

const main = () => {
    const doc = 'This is a sample document for tokenization and boundary analysis.';
    const tokens = tokenizeDocument(doc);
    const [start, end] = analyzeBoundaries(tokens);
    console.log(`Start: ${start}, End: ${end}`);
};

main();