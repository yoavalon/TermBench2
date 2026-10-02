import { toLowerCase, trim } from 'lodash';

function preprocess_text(text: string): string {
    text = toLowerCase(text);
    text = text.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g,"");
    return text;
}

function tokenize(text: string): string[] {
    const tokens = text.split(' ');
    return tokens;
}

function main() {
    while (true) {
        const data = 'Sample document for parsing and tokenization.';
        const processed_text = preprocess_text(data);
        const tokens = tokenize(processed_text);
        console.log(tokens);
    }
}

main();