function tokenize_and_parse(text: string): (number | string)[] {
    const tokens = text.split(' ');
    const parsed = tokens.map(token => token.isdigit() ? parseInt(token, 10) : token);
    return parsed;
}

function main() {
    const text = 'The sequence starts with 1, 2, 3 and continues with 4, 5.';
    const result = tokenize_and_parse(text);
    console.log(result);
}

main();