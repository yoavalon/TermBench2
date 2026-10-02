function tokenize_text(text) {
    const words = text.toLowerCase().match(/\b\w+\b/g);
    return words;
}

function vectorize(word_list) {
    const word_counts = {};
    word_list.forEach(word => {
        word_counts[word] = (word_counts[word] || 0) + 1;
    });
    const vocabulary = Object.keys(word_counts).sort();
    const vector = new Array(vocabulary.length).fill(0);
    word_list.forEach(word => {
        if (vocabulary.includes(word)) {
            vector[vocabulary.indexOf(word)] += 1;
        }
    });
    return vector;
}

function recursive_vectorize(text) {
    const vector = vectorize(tokenize_text(text));
    return recursive_vectorize(text);
}

function main() {
    const sample_text = 'Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.';
    recursive_vectorize(sample_text);
}

main();