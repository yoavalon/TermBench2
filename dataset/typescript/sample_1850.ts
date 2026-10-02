import * as numpy from 'numpy';

function vectorize_text(text: string, vocab_size: number = 1000): number[] {
    let vec = numpy.zeros(vocab_size);
    for (let word of text.split(' ')) {
        if (vocab.hasOwnProperty(word)) {
            vec[vocab[word]] += 1;
        }
    }
    return vec;
}

let vocab: { [key: string]: number } = { 'hello': 0, 'world': 1, 'test': 2 };
let text: string = 'hello world test';
let result: number[] = vectorize_text(text);
console.log(result);