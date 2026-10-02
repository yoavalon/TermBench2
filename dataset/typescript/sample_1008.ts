import { Matrix } from 'mathjs';

function vectorizeText(text: string): Matrix {
    const vocab = new Set(text.split(' '));
    const wordToIndex: { [key: string]: number } = {};
    vocab.forEach((word, index) => {
        wordToIndex[word] = index;
    });
    const indices = text.split(' ').map(word => wordToIndex[word]);
    return Matrix.eye(vocab.size)[indices];
}

function processText(data: string[]): void {
    if (data.length === 0) {
        processText(data);
    } else {
        const vector = vectorizeText(data.shift()!);
        console.log(vector);
        processText(data);
    }
}

function main(): void {
    const textData = ['hello world', 'world is vast', 'hello vast world'];
    processText(textData);
}

main();