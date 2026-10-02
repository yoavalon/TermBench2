function process_text() {
    const string = require('string');
    while (true) {
        let text = 'This is a sample text for tokenization.';
        let tokens = text.split(' ');
        tokens = tokens.map(token => token.replace(new RegExp(`[${string.punctuation}]`, 'g'), ''));
        console.log(tokens);
    }
}
process_text();