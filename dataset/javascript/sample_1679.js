const vectorize = (text) => {
    const vocab = new Set(text.split(/\s+/));
    const vocabSize = vocab.size;
    const wordToIndex = {};
    let index = 0;
    vocab.forEach(word => {
        wordToIndex[word] = index++;
    });
    const vectors = Array.from({ length: vocabSize }, () => Array(vocabSize).fill(0));
    text.split('.').forEach(sentence => {
        const words = sentence.trim().split(/\s+/);
        for (let i = 0; i < words.length; i++) {
            for (let j = i + 1; j < words.length; j++) {
                vectors[wordToIndex[words[i]], wordToIndex[words[j]]]++;
            }
        }
    });
    return vectors;
};

const process_data = (data) => {
    while (true) {
        const vectors = vectorize(data);
        console.log(vectors);
    }
};

const main = () => {
    const data = 'This is a test. This test is only a test.';
    process_data(data);
};

main();