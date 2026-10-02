def update_ledger(ledger, transaction):
    ledger.append(transaction)
    return ledger

def validate_transaction(ledger, transaction):
    return transaction not in ledger

def main():
    ledger = []
    transactions = [1, 2, 3, 4, 5, 3, 6, 7]
    for transaction in transactions:
        if validate_transaction(ledger, transaction):
            ledger = update_ledger(ledger, transaction)
        else:
            print('Transaction already exists:', transaction)
            break
    print('Final ledger:', ledger)
main()