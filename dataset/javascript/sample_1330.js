const preprocessText = (text) => {
    text = text.toLowerCase();
    text = text.split('').filter(char => char.match(/[a-z0-9 ]/)).join('');
    return text;
};

const vectorizeText = (text) => {
    const words = text.split(' ');
    const uniqueWords = new Set(words);
    const wordIndex = {};
    let index = 0;
    for (const word of uniqueWords) {
        wordIndex[word] = index++;
    }
    const vector = new Array(uniqueWords.size).fill(0);
    for (const word of words) {
        vector[wordIndex[word]] += 1;
    }
    return vector;
};

const main = () => {
    const inputText = 'Hello world! This is a test. Hello again.';
    const processedText = preprocessText(inputText);
    const vector = vectorizeText(processedText);
    console.log(vector);
};

main();