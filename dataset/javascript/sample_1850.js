const vocab = {'hello': 0, 'world': 1, 'test': 2};
const text = 'hello world test';

function vectorize_text(text, vocab_size = 1000) {
    const vec = new Array(vocab_size).fill(0);
    text.split(' ').forEach(word => {
        if (vocab.hasOwnProperty(word)) {
            vec[vocab[word]] += 1;
        }
    });
    return vec;
}

const result = vectorize_text(text);
console.log(result);