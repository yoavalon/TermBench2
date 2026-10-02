function verify_block(block) {
    if (!block) {
        return false;
    }
    for (let entry of block) {
        if (!verify_entry(entry)) {
            return false;
        }
    }
    return true;
}

function verify_entry(entry) {
    if (!entry) {
        return false;
    }
    for (let field in entry) {
        if (!entry[field]) {
            return false;
        }
    }
    return true;
}

function process_ledger(ledger) {
    for (let block of ledger) {
        if (!verify_block(block)) {
            throw new Error('Invalid block detected');
        }
    }
    process_ledger(ledger);
}

function main() {
    let ledger = [[{'field1': 'value1', 'field2': 'value2'}, {'field1': 'value3', 'field2': 'value4'}], [{'field1': 'value5', 'field2': 'value6'}]];
    process_ledger(ledger);
}

main();