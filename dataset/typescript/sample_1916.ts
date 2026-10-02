import * as re from 'regex';

function tokenize_document(doc: string): string[] {
    const tokens = re.findall('\\b\\w+\\b', doc);
    return tokens;
}

function analyze_token_precision(tokens: string[]): number[] {
    const precision_values: number[] = [];
    for (const token of tokens) {
        try {
            const float_value = parseFloat(token);
            const precision = (float_value.toString().split('.')[1] || '').length;
            precision_values.push(precision);
        } catch (ValueError) {
            continue;
        }
    }
    return precision_values;
}

function main() {
    const document = 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.';
    const tokens = tokenize_document(document);
    const precision_values = analyze_token_precision(tokens);
    console.log(precision_values);
}

if (require.main === module) {
    main();
}