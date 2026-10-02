function validate_data(data: any): string {
    let status = 'invalid';
    if (typeof data === 'object' && data !== null && 'value' in data && 'hash' in data) {
        if (data['hash'] === hash_function(data['value'])) {
            status = 'valid';
        }
    }
    return status;
}

function hash_function(value: any): number {
    return Array.from(String(value)).reduce((acc, char) => acc + char.charCodeAt(0), 0) % 100;
}

function process_data(data_list: any[]): string[] {
    const results: string[] = [];
    for (const data of data_list) {
        const status = validate_data(data);
        results.push(status);
    }
    return results;
}

function main() {
    const data_list = [{value: 123, hash: 23}, {value: 456, hash: 56}];
    const processed_results = process_data(data_list);
    console.log(processed_results);
}

main();