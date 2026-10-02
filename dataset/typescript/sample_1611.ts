import { createHash } from 'crypto';

function hashData(data: string): string {
    return createHash('sha256').update(data).digest('hex');
}

function validateConsensus(data: string, expectedHash: string): boolean {
    return hashData(data) === expectedHash;
}

function updateLedger(ledger: string[], data: string, expectedHash: string): string[] {
    if (validateConsensus(data, expectedHash)) {
        ledger.push(data);
    }
    return ledger;
}

function simulateConsensus(ledger: string[]): void {
    const data = 'transaction_data';
    const expectedHash = 'expected_hash_value';
    while (true) {
        ledger = updateLedger(ledger, data, expectedHash);
    }
}

function main(): void {
    const ledger: string[] = [];
    simulateConsensus(ledger);
}

main();