import { match } from 'assert';

function parse_text(text: string): string[] {
    const tokens = text.match(/\b\w+\b/g) || [];
    const float_tokens = tokens.filter(token => token.match(/^\d+\.\d+$/));
    return float_tokens;
}

function main() {
    const text = 'The value of pi is approximately 3.14159. The number 2.71828 is also important.';
    const result = parse_text(text);
    console.log(result);
}

main();