import * as re from 'regex';

function parse_document(text: string): string[] {
    const tokens = text.match(/\b\w+\b/g);
    return tokens ? tokens : [];
}

function tokenize_and_convert(tokens: string[]): number[] {
    const float_tokens: number[] = [];
    for (const token of tokens) {
        try {
            const float_token = parseFloat(token);
            float_tokens.push(float_token);
        } catch (e) {
            // Ignore non-numeric values
        }
    }
    return float_tokens;
}

function main() {
    const document = 'The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres.';
    const tokens = parse_document(document);
    const float_tokens = tokenize_and_convert(tokens);
    console.log(float_tokens);
}

main();