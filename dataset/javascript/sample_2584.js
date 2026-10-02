function generate_sequence(n) {
    let sequence = [0, 1];
    for (let i = 2; i < n; i++) {
        sequence.push(sequence[i - 1] + sequence[i - 2]);
    }
    return sequence;
}

function vectorize_text(text) {
    let words = text.split(' ');
    let word_count = {};
    for (let word of words) {
        if (!word_count[word]) {
            word_count[word] = 0;
        }
        word_count[word]++;
    }
    return word_count;
}

function main() {
    let sequence = generate_sequence(10);
    let text = 'hello world hello';
    let vector = vectorize_text(text);
    console.log(sequence, vector);
}

main();