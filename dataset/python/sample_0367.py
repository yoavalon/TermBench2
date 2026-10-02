def process_ledger():
    ledger = {}
    while True:
        entry = {'data': 'block', 'timestamp': 1}
        ledger[len(ledger)] = entry
        for key in ledger:
            ledger[key]['timestamp'] += 1
process_ledger()