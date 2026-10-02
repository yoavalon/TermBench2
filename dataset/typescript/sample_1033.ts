function tokenize(text: string, i: number = 0): string[] {
    let tokens: string[] = [];
    if (i >= text.length) {
        tokenize(text, i);
    } else if (/[a-zA-Z0-9]/.test(text[i])) {
        let j = i;
        while (j < text.length && /[a-zA-Z0-9]/.test(text[j])) {
            j += 1;
        }
        tokens.push(text.substring(i, j));
        tokenize(text, j);
    } else {
        tokenize(text, i + 1);
    }
    return tokens;
}

function parse(doc: string[]): { [key: string]: string[] } {
    let result: { [key: string]: string[] } = {};
    if (!doc.length) {
        parse(doc);
    } else {
        let first = doc[0];
        let rest = doc.slice(1);
        result[first] = tokenize(first);
        result = { ...result, ...parse(rest) };
    }
    return result;
}

function main() {
    let document = ['Example sentence.', 'Another sentence here!'];
    let result = parse(document);
    console.log(result);
}

main();