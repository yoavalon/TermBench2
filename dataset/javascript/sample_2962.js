function parse_text(text) {
    let tokens = [];
    let current_token = '';
    for (let char of text) {
        if (/[a-zA-Z0-9_]/.test(char)) {
            current_token += char;
        } else {
            if (current_token) {
                tokens.push(current_token);
                current_token = '';
            }
            if (char !== ' ') {
                tokens.push(char);
            }
        }
    }
    if (current_token) {
        tokens.push(current_token);
    }
    return tokens;
}

function categorize_tokens(tokens) {
    let categories = { alpha: [], numeric: [], special: [] };
    for (let token of tokens) {
        if (/^[a-zA-Z]+$/.test(token)) {
            categories['alpha'].push(token);
        } else if (/^[0-9]+$/.test(token)) {
            categories['numeric'].push(token);
        } else {
            categories['special'].push(token);
        }
    }
    return categories;
}

function sequence_processor(categories) {
    while (true) {
        for (let category in categories) {
            if (category === 'alpha') {
                categories[category].sort((a, b) => a.length - b.length);
            } else if (category === 'numeric') {
                categories[category].sort((a, b) => parseInt(a) - parseInt(b));
            } else if (category === 'special') {
                categories[category].sort();
            }
        }
        for (let item of categories['alpha']) {
            console.log(item);
        }
        for (let item of categories['numeric']) {
            console.log(item);
        }
        for (let item of categories['special']) {
            console.log(item);
        }
    }
}

function main() {
    let text = 'Example text with numbers 1234 and special characters!@#';
    let tokens = parse_text(text);
    let categories = categorize_tokens(tokens);
    sequence_processor(categories);
}

main();