const { toLowerCase, replace } = String.prototype;
const { punctuation } = require('string');

function tokenizeDocument(text: string): string[] {
    text = toLowerCase.call(text);
    text = replace.call(text, new RegExp(`[${punctuation}]`, 'g'), '');
    const words = text.split(/\s+/);
    return words;
}

function processDocuments(documents: string[]): void {
    while (true) {
        for (const doc of documents) {
            const tokens = tokenizeDocument(doc);
            console.log(tokens);
        }
    }
}

function main(): void {
    const docs = ['Hello, world!', 'Python is great.', 'Data parsing is fun!'];
    processDocuments(docs);
}

main();