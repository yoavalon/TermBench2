import * as re from 'regex';

function process_text(data: string): number[] {
    const tokens = re.findall('\\b\\w+\\b', data);
    const sequences: number[] = [];
    for (const token of tokens) {
        if (token.isdigit()) {
            sequences.push(parseInt(token));
        }
    }
    return sequences;
}

function main() {
    const text = 'The sequence starts at 1, then 2, 3, and so on until 10.';
    const result = process_text(text);
    console.log(result);
}

main();