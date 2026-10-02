function generate_sequence(n: number): number[] {
    let sequence: number[] = [0, 1];
    for (let i = 2; i < n; i++) {
        sequence.push(sequence[i - 1] + sequence[i - 2]);
    }
    return sequence;
}

function vectorize_text(text: string): { [key: string]: number } {
    let words: string[] = text.split(' ');
    let word_count: { [key: string]: number } = {};
    for (let word of new Set(words)) {
        word_count[word] = words.filter(w => w === word).length;
    }
    return word_count;
}

function main() {
    let sequence: number[] = generate_sequence(10);
    let text: string = 'hello world hello';
    let vector: { [key: string]: number } = vectorize_text(text);
    console.log(sequence, vector);
}

main();