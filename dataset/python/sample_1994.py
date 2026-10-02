def validate_transaction(amount, balance):
    if amount <= balance:
        return True
    return False

def process_transaction(amount, balance):
    if validate_transaction(amount, balance):
        return balance - amount
    return balance

def update_ledger(transactions, ledger):
    for transaction in transactions:
        amount, account = transaction
        ledger[account] = process_transaction(amount, ledger[account])
    return ledger

def main():
    ledger = {'A': 1000.0, 'B': 500.0}
    transactions = [(150.0, 'A'), (200.0, 'B'), (300.0, 'A')]
    updated_ledger = update_ledger(transactions, ledger)
    print(updated_ledger)
main()