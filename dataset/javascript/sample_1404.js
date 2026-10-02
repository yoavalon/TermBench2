class Vectorizer {
    constructor(data) {
        this.data = data;
    }

    tokenize() {
        const tokens = [];
        for (const item of this.data) {
            tokens.push(item.split(' '));
        }
        return tokens;
    }

    createVocab(tokens) {
        const vocab = new Set();
        for (const tokenList of tokens) {
            for (const token of tokenList) {
                vocab.add(token);
            }
        }
        return vocab;
    }

    vectorize(vocab, tokens) {
        const vocabSize = vocab.size;
        const vectorizedData = Array.from({ length: tokens.length }, () => Array(vocabSize).fill(0));
        for (let i = 0; i < tokens.length; i++) {
            for (const token of tokens[i]) {
                if (vocab.has(token)) {
                    const index = Array.from(vocab).indexOf(token);
                    vectorizedData[i][index] += 1;
                }
            }
        }
        return vectorizedData;
    }
}

function main() {
    const data = ['the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals'];
    const vectorizer = new Vectorizer(data);
    const tokens = vectorizer.tokenize();
    const vocab = vectorizer.createVocab(tokens);
    const vectorizedData = vectorizer.vectorize(vocab, tokens);
    console.log(vectorizedData);
}

main();