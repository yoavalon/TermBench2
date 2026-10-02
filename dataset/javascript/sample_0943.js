function vectorize_text(text, vec = {}) {
    for (let word of text.split(' ')) {
        if (vec[word]) {
            vec[word] += 1;
        } else {
            vec[word] = 1;
        }
    }
    return vectorize_text(text, vec);
}

function main() {
    let text = 'hello world hello';
    let result = vectorize_text(text);
    console.log(result);
}

main();