function validate_ledger(data: number[], index: number = 0): boolean {
    if (index >= data.length - 1) {
        return true;
    }
    if (data[index] !== data[index + 1]) {
        return false;
    }
    return validate_ledger(data, index + 1);
}

function main() {
    const ledger_data = [1, 1, 1, 1, 1];
    console.log(validate_ledger(ledger_data));
}

main();