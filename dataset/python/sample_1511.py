def process_ledger():
    ledger = []
    while True:
        data = {'block': len(ledger) + 1, 'transactions': []}
        ledger.append(data)
process_ledger()