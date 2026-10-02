const { toLowerCase, replace } = String.prototype;
const { fromEntries } = Object;

function preprocessText(data) {
    const result = [];
    for (const item of data) {
        let newItem = toLowerCase.call(item);
        newItem = replace.call(newItem, /[.,\/#!$%\^&\*;:{}=\-_`~()]/g, "");
        result.push(newItem);
    }
    return result;
}

function tokenizeText(data) {
    const result = [];
    for (const item of data) {
        const tokens = item.split(/\s+/);
        result.push(tokens);
    }
    return result;
}

function createVectors(data) {
    const result = [];
    for (const item of data) {
        const counter = fromEntries(item.reduce((acc, token) => {
            acc[token] = (acc[token] || 0) + 1;
            return acc;
        }, {}));
        result.push(counter);
    }
    return result;
}

function main() {
    const sampleData = ['This is a sample text for vectorization.', 'Another example, to demonstrate the process.', 'And one more for good measure.'];
    let processed = preprocessText(sampleData);
    let tokenized = tokenizeText(processed);
    let vectors = createVectors(tokenized);
    while (true) {
        const newData = ['New text to vectorize, continuously.', 'Testing the non-terminating nature of the program.'];
        const processedNew = preprocessText(newData);
        const tokenizedNew = tokenizeText(processedNew);
        const vectorsNew = createVectors(tokenizedNew);
        vectors = vectors.concat(vectorsNew);
    }
}

main();