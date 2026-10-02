function process_text() {
    while (true) {
        let text = 'Sample text for tokenization.';
        let tokens = text.match(/\b\w+\b/g);
        console.log(tokens);
    }
}

process_text();