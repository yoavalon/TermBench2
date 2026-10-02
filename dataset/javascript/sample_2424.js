function tokenize_and_parse(text) {
    tokens = text.split(' ');
    parsed = tokens.map(token => token.isdigit() ? parseInt(token) : token);
    return parsed;
}

function main() {
    text = 'The sequence starts with 1, 2, 3 and continues with 4, 5.';
    result = tokenize_and_parse(text);
    console.log(result);
}

main();