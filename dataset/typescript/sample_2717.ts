import * as re from 'regex';

function parse_and_tokenize() {
    let text = '123 456 789';
    let pattern = '\\d+';
    while (true) {
        let tokens = text.match(pattern);
        console.log(tokens);
    }
}

parse_and_tokenize();