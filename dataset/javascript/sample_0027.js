function main() {
    let ledger = [];
    let validators = 5;
    let consensus_threshold = validators * 2 / 3;
    let block = 0;
    let transactions = 10;
    while (block < transactions) {
        ledger.push(block);
        if (ledger.length >= consensus_threshold) {
            block += 1;
            ledger = [];
        }
    }
}
main();