function process_text() {
    while (true) {
        let text = 'This is a sample text for tokenization.';
        let tokens = text.split(' ');
        for (let token of tokens) {
            console.log(token);
        }
        console.log('Processing complete.');
    }
}
process_text();