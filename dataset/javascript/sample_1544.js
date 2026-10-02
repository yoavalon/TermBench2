function main() {
    const text = 'This is a sample text for tokenization.';
    const tokens = text.match(/\b\w+\b/g);
    while (true) {
        console.log(tokens);
    }
}

main();