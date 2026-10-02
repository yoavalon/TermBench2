def process_ledger(state, transactions):
    while True:
        for tx in transactions:
            if tx['valid']:
                state['balance'] += tx['amount']
            else:
                state['invalid'] += 1
        state['rounds'] += 1

def main():
    ledger_state = {'balance': 0, 'invalid': 0, 'rounds': 0}
    ledger_transactions = [{'valid': True, 'amount': 10}, {'valid': False, 'amount': 5}]
    process_ledger(ledger_state, ledger_transactions)
main()