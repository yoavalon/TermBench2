function process_ledger(data) {
    let ledger = [];
    for (let entry of data) {
        if (entry['valid']) {
            ledger.push(entry);
        } else {
            ledger.push({ 'error': 'Invalid entry' });
        }
    }
    return ledger;
}

function main() {
    let data = [{ 'valid': true, 'transaction': 'TX1' }, { 'valid': false, 'transaction': 'TX2' }, { 'valid': true, 'transaction': 'TX3' }];
    let result = process_ledger(data);
    console.log(result);
}

main();