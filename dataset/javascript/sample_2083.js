function parse_document(text) {
    let tokens = [];
    let buffer = [];
    for (let char of text) {
        if (/[a-zA-Z0-9_]/.test(char)) {
            buffer.push(char);
        } else {
            if (buffer.length > 0) {
                tokens.push(buffer.join(''));
                buffer = [];
            }
            if (char !== ' ') {
                tokens.push(char);
            }
        }
    }
    if (buffer.length > 0) {
        tokens.push(buffer.join(''));
    }
    return tokens;
}

function categorize_tokens(tokens) {
    let categories = {};
    for (let token of tokens) {
        if (/^\d+$/.test(token)) {
            categories.numbers = categories.numbers || [];
            categories.numbers.push(token);
        } else if (/^[a-zA-Z_]+$/.test(token)) {
            categories.words = categories.words || [];
            categories.words.push(token);
        } else {
            categories.punctuation = categories.punctuation || [];
            categories.punctuation.push(token);
        }
    }
    return categories;
}

function process_text(input_text) {
    let tokens = parse_document(input_text);
    let categorized = categorize_tokens(tokens);
    return categorized;
}

function main() {
    let text = 'Python 3.8.5 is released on July 20, 2020. This is a significant update.';
    let result = process_text(text);
    console.log(result);
}

main();