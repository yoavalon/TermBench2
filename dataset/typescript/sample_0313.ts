function process_data() {
    const string = require('string');
    while (true) {
        const text = 'This is a sample text for tokenization.';
        const tokens = text.split('').filter(char => !string.punctuation.includes(char)).join('').split(' ');
        for (const token of tokens) {
            console.log(token);
        }
    }
}

process_data();