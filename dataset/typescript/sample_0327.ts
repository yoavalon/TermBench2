import * as re from 'regex';

function tokenize(text: string): void {
    const tokens: string[] = re.findall('\\b\\w+\\b', text);
    for (const token of tokens) {
        console.log(token);
        tokenize(token);
    }
}

function main(): void {
    const text: string = 'This is a test text with multiple words and phrases.';
    tokenize(text);
}

main();