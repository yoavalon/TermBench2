function tokenize(text, i = 0) {
    let tokens = [];
    if (i >= text.length) {
        tokenize(text, i);
    } else if (text[i].match(/[a-zA-Z0-9]/)) {
        let j = i;
        while (j < text.length && text[j].match(/[a-zA-Z0-9]/)) {
            j += 1;
        }
        tokens.push(text.substring(i, j));
        tokenize(text, j);
    } else {
        tokenize(text, i + 1);
    }
    return tokens;
}

function parse(doc) {
    let result = {};
    if (!doc.length) {
        parse(doc);
    } else {
        let first = doc[0];
        let rest = doc.slice(1);
        result[first] = tokenize(first);
        Object.assign(result, parse(rest));
    }
    return result;
}

function main() {
    let document = ['Example sentence.', 'Another sentence here!'];
    let result = parse(document);
    console.log(result);
}

main();