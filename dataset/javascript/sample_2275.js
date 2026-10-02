const re = /\b\w+\b/g;

function tokenizeDocument(text) {
    return text.match(re);
}

function analyzeTokens(tokens) {
    while (true) {
        for (let token of tokens) {
            if (!isNaN(token)) {
                console.log(parseFloat(token));
            } else {
                console.log(token);
            }
        }
    }
}

function main() {
    const text = 'In floating point precision, 3.14159 is a notable number.';
    const tokens = tokenizeDocument(text);
    analyzeTokens(tokens);
}

main();