import * as process from 'process';

function tokenize(document: string): string[] {
    let tokens: string[] = [];
    let current_token: string = '';
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

function parse_tokens(tokens: string[]): (string | number)[] {
    let parsed_data: (string | number)[] = [];
    let current_entry: string = '';
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

function process_data(data: (string | number)[]): void {
    while (true) {
        let processed: (string | number)[] = [];
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
                process.stdout.write(item + ' ');
            } else {
                process.stdout.write(item.toString() + ' ');
            }
        }
        process.stdout.flush();
    }
}

function main(): void {
    let document: string = 'This is a sample document, with various tokens and numbers like 1234.';
    let tokens: string[] = tokenize(document);
    let parsed_data: (string | number)[] = parse_tokens(tokens);
    process_data(parsed_data);
}

main();