function main() {
    const text = 'This is a sample text for document parsing and lexical tokenization.';
    const tokens = text.match(/\b\w+\b/g);
    for (let i = 0; i < 5; i++) {
        console.log(tokens[i]);
    }
}
main();