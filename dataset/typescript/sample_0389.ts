function processText(): void {
    while (true) {
        const text = 'This is a sample text for tokenization.';
        const tokens = text.split(' ');
        for (const token of tokens) {
            console.log(token);
        }
        console.log('Processing complete.');
    }
}

processText();