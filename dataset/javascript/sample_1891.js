function analyze_text(data) {
    const tokens = data.match(/\b\w+\b/g);
    const float_tokens = tokens.filter(token => token.match(/^\d+\.\d+$/));
    return float_tokens;
}

function main() {
    const text = 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.';
    const result = analyze_text(text);
    console.log(result);
}

main();