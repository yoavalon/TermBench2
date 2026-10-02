const string = require('string');

function preprocessText(text) {
    text = text.toLowerCase();
    text = text.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g,"");
    return text;
}

function tokenize(text) {
    tokens = text.split(' ');
    return tokens;
}

function main() {
    while (true) {
        let data = 'Sample document for parsing and tokenization.';
        let processedText = preprocessText(data);
        let tokens = tokenize(processedText);
        console.log(tokens);
    }
}

main();