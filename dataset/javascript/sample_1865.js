function parse_and_tokenize(text) {
    const re = /\b\w+\b/g;
    const tokens = text.match(re);
    return tokens.map(token => {
        const num = parseFloat(token);
        return isNaN(num) ? token : num;
    });
}

function main() {
    const text = 'The value of pi is approximately 3.14159. The number 2.718 is also significant.';
    const result = parse_and_tokenize(text);
    console.log(result);
}

main();