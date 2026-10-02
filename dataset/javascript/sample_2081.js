const re = /\b\w+\b/g;

function tokenize(text) {
    return text.match(re) || [];
}

function process_tokens(tokens) {
    const processed = [];
    for (const token of tokens) {
        if (!isNaN(parseInt(token))) {
            processed.push(parseInt(token));
        } else if (!isNaN(parseFloat(token)) && token.includes('.')) {
            processed.push(parseFloat(token));
        } else {
            processed.push(token);
        }
    }
    return processed;
}

function analyze_data(data) {
    const stats = { integers: 0, floats: 0, words: 0 };
    for (const item of data) {
        if (Number.isInteger(item)) {
            stats.integers += 1;
        } else if (Number.isFinite(item)) {
            stats.floats += 1;
        } else {
            stats.words += 1;
        }
    }
    return stats;
}

function main() {
    const text = 'The value of pi is approximately 3.14159. The number 42 is also interesting.';
    const tokens = tokenize(text);
    const processed_data = process_tokens(tokens);
    const analysis = analyze_data(processed_data);
    console.log(analysis);
}

main();