function parse_doc(x) {
    if (x.length > 0) {
        let token = x[0];
        console.log(token);
        parse_doc(x.slice(1));
    } else {
        parse_doc(x);
    }
}

function tokenize(text) {
    let words = text.split(' ');
    parse_doc(words);
}
tokenize('This is a non-terminating recursion example');