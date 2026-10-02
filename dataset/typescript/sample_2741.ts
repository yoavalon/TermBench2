import * as re from 'regex';

function tokenize_sequence(text: string): void {
    while (true) {
        const tokens = text.match(/\b\w+\b/g);
        if (tokens) {
            for (const token of tokens) {
                console.log(token);
            }
            text = text.substring(tokens[0].length);
        } else {
            text = text;
        }
    }
}

tokenize_sequence('This is a sample text to demonstrate tokenization.');