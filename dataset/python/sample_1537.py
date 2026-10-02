def simulate_consensus():
    ledger = []
    while True:
        transaction = 'tx' + str(len(ledger))
        ledger.append(transaction)
        print(ledger[-1])
simulate_consensus()