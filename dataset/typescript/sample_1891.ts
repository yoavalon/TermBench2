function analyze_text(data: string): string[] {
    const re = /\b\w+\b/g;
    const tokens = data.match(re) || [];
    const float_tokens = tokens.filter(token => /^\d+\.\d+$/.test(token));
    return float_tokens;
}

function main() {
    const text = 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.';
    const result = analyze_text(text);
    console.log(result);
}

main();