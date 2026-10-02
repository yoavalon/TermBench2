function vectorize_text(text, vectors, depth) {
    if (depth == 0) {
        return vectors;
    }
    words = text.split(' ');
    for (let word of words) {
        vectors.push(word);
    }
    return vectorize_text(text, vectors, depth - 1);
}

function main() {
    let text = 'recursion in natural language processing';
    let vectors = [];
    let result = vectorize_text(text, vectors, 3);
    console.log(result);
}

main();