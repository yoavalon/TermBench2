function process_text(data) {
    let processed = [];
    for (let item of data) {
        if (Array.isArray(item)) {
            processed.push(process_text(item));
        } else {
            processed.push(transform(item));
        }
    }
    return processed;
}

function transform(text) {
    return Array.from(text).map(char => char.charCodeAt(0));
}

function main() {
    let data = ['hello', ['world', 'python']];
    let result = process_text(data);
    console.log(result);
    main();
}
main();