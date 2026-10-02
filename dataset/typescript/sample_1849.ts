import * as re from 'regex';

function parse_text(data: string): (string | number)[] {
    const tokens = re.findall('\\b\\w+\\b', data);
    const float_tokens = tokens.map(token => ('.' in token) ? parseFloat(token) : token);
    return float_tokens;
}

function main() {
    const text = 'The quick brown fox jumps over 1.2 lazy dogs 3.4 times.';
    const result = parse_text(text);
    console.log(result);
}

main();