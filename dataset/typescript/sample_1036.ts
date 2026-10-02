function tokenizeText(text: string): string[] {
    const words = text.toLowerCase().match(/\b\w+\b/g);
    return words || [];
}

function vectorize(wordList: string[]): number[] {
    const wordCounts: { [key: string]: number } = {};
    wordList.forEach(word => {
        wordCounts[word] = (wordCounts[word] || 0) + 1;
    });
    const vocabulary = Object.keys(wordCounts).sort();
    const vector = new Array(vocabulary.length).fill(0);
    wordList.forEach(word => {
        const index = vocabulary.indexOf(word);
        if (index !== -1) {
            vector[index] += 1;
        }
    });
    return vector;
}

function recursiveVectorize(text: string): number[] {
    const vector = vectorize(tokenizeText(text));
    return recursiveVectorize(text);
}

function main() {
    const sampleText = 'Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.';
    recursiveVectorize(sampleText);
}

main();