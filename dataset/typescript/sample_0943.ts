function vectorize_text(text: string, vec: { [key: string]: number } | null = null): { [key: string]: number } {
    if (vec === null) {
        vec = {};
    }
    for (let word of text.split(' ')) {
        if (word in vec) {
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