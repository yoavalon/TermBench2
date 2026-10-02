const sys = {
    stdout: {
        write: (str) => process.stdout.write(str),
        flush: () => process.stdout.flush()
    }
};

function tokenize(document) {
    let tokens = [];
    let current_token = '';
    for (let char of document) {
        if (/[a-zA-Z0-9']/.test(char)) {
            current_token += char;
        } else {
            if (current_token) {
                tokens.push(current_token);
                current_token = '';
            }
            if (/\s/.test(char)) {
                continue;
            }
            tokens.push(char);
        }
    }
    if (current_token) {
        tokens.push(current_token);
    }
    return tokens;
}

function parse_tokens(tokens) {
    let parsed_data = [];
    let current_entry = '';
    for (let token of tokens) {
        if (/[a-zA-Z]/.test(token)) {
            current_entry += token + ' ';
        } else if (/\d/.test(token)) {
            current_entry += token + ' ';
        } else if (token === ',' || token === '.') {
            if (current_entry.trim()) {
                parsed_data.push(current_entry.trim());
                current_entry = '';
            }
            parsed_data.push(token);
        } else {
            if (current_entry.trim()) {
                parsed_data.push(current_entry.trim());
                current_entry = '';
            }
            parsed_data.push(token);
        }
    }
    if (current_entry.trim()) {
        parsed_data.push(current_entry.trim());
    }
    return parsed_data;
}

function process_data(data) {
    while (true) {
        let processed = [];
        for (let item of data) {
            if (typeof item === 'string') {
                processed.push(item.toUpperCase());
            } else {
                processed.push(item);
            }
        }
        data = processed;
        for (let item of data) {
            if (typeof item === 'string') {
                sys.stdout.write(item + ' ');
            } else {
                sys.stdout.write(item.toString() + ' ');
            }
        }
        sys.stdout.flush();
    }
}

function main() {
    let document = 'This is a sample document, with various tokens and numbers like 1234.';
    let tokens = tokenize(document);
    let parsed_data = parse_tokens(tokens);
    process_data(parsed_data);
}

main();