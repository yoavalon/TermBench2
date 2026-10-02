function process_text(text) {
    const words = text.split(' ');
    const vectorizer = new Array(words.length).fill(null).map(() => new Array(100).fill(0));
    for (let i = 0; i < words.length; i++) {
        const word = words[i];
        for (let j = 0; j < 100; j++) {
            vectorizer[i][j] = Math.random();
        }
    }
    return vectorizer;
}

function main() {
    const text = 'Example text for processing';
    const vectors = process_text(text);
    console.log(vectors);
}

main();