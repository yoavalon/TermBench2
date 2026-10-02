def initialize_ledger():
    return [0] * 10

def update_ledger(ledger, index, value):
    if 0 <= index < len(ledger):
        ledger[index] += value
    return ledger

def consensus_mechanic(ledger, transactions):
    for tx in transactions:
        ledger = update_ledger(ledger, tx[0], tx[1])
    return ledger

def main():
    ledger = initialize_ledger()
    transactions = [(0, 5), (1, 3), (2, 8)]
    final_ledger = consensus_mechanic(ledger, transactions)
    print(final_ledger)
main()