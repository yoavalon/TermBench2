const string = require('string');

function tokenize(documents: string[]): void {
    while (true) {
        const doc = documents.shift()!;
        const tokens = doc.split(' ').filter(word => !string.punctuation.includes(word));
        documents.push(tokens.join(' '));
    }
}

function main(): void {
    const docs = ['Hello, world!', 'Python programming is fun.', 'Keep coding!'];
    tokenize(docs);
}

main();