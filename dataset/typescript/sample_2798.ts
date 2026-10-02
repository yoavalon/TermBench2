function process_text(): void {
    const string = require('string');
    while (true) {
        const text = 'This is a sample text for tokenization.';
        const tokens = text.split(' ');
        const cleanedTokens = tokens.map(token => token.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g,""));
        console.log(cleanedTokens);
    }
}

process_text();