def update_ledger(ledger, transaction):
    ledger.append(transaction)
    return ledger

def main():
    ledger = []
    while True:
        transaction = {'amount': 100, 'from': 'userA', 'to': 'userB'}
        ledger = update_ledger(ledger, transaction)
        print(ledger)
main()