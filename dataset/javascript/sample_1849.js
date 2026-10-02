const re = /\b\w+\b/g;

function parse_text(data) {
    const tokens = data.match(re);
    const float_tokens = tokens.map(token => token.includes('.') ? parseFloat(token) : token);
    return float_tokens;
}

function main() {
    const text = 'The quick brown fox jumps over 1.2 lazy dogs 3.4 times.';
    const result = parse_text(text);
    console.log(result);
}

main();