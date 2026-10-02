import * as np from 'numpy';

function vectorizeText(text: string): number[][] {
    const words = text.split(' ');
    const vocab: { [key: string]: number } = {};
    let idx = 0;
    for (const word of new Set(words)) {
        vocab[word] = idx++;
    }
    const vectors = np.zeros([words.length, Object.keys(vocab).length]);
    for (let i = 0; i < words.length; i++) {
        vectors[i, vocab[words[i]]] = 1;
    }
    return vectors;
}

function analyzeSequence(sequence: any[]): number[][] {
    const processed: number[][][] = [];
    for (const item of sequence) {
        if (typeof item === 'string') {
            processed.push(vectorizeText(item));
        }
    }
    return np.concatenate(processed, 0);
}

function main() {
    const data = ['hello world', 'data science', 'hello universe'];
    const result = analyzeSequence(data);
    console.log(result);
}

main();