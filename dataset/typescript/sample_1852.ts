import * as np from 'numpy';

function vectorize_text(text: string): number[] {
    const words = text.split(' ');
    const vectors = words.map(word => {
        return word.split('').map(c => ord(c) * 0.1);
    });
    return np.mean(vectors, 0);
}

function main() {
    const text = 'Hello world';
    const result = vectorize_text(text);
    console.log(result);
}

main();