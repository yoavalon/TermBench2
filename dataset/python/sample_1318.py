def update_ledger(state, transaction):
    state[transaction['id']] = transaction['value']
    return state

def validate_transaction(state, transaction):
    if transaction['id'] in state and state[transaction['id']] != transaction['value']:
        return False
    return True

def main():
    ledger = {}
    transactions = [{'id': 1, 'value': 100}, {'id': 2, 'value': 200}, {'id': 1, 'value': 150}]
    for transaction in transactions:
        if validate_transaction(ledger, transaction):
            ledger = update_ledger(ledger, transaction)
    print(ledger)
main()