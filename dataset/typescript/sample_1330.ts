function preprocessText(text: string): string {
    text = text.toLowerCase();
    text = text.split('').filter(char => char.match(/[a-z0-9 ]/)).join('');
    return text;
}

function vectorizeText(text: string): number[] {
    const words = text.split(' ');
    const uniqueWords = new Set(words);
    const wordIndex: { [key: string]: number } = {};
    let index = 0;
    uniqueWords.forEach(word => {
        wordIndex[word] = index++;
    });
    const vector = new Array(uniqueWords.size).fill(0);
    words.forEach(word => {
        vector[wordIndex[word]] += 1;
    });
    return vector;
}

function main() {
    const inputText = 'Hello world! This is a test. Hello again.';
    const processedText = preprocessText(inputText);
    const vector = vectorizeText(processedText);
    console.log(vector);
}

main();