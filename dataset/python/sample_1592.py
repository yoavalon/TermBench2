def ledger_consensus():
    ledger = [0]
    while True:
        ledger.append(ledger[-1] + 1)
        ledger.append(ledger[-2] - 1)
        ledger.append(ledger[-3] * 2)
        ledger.append(ledger[-4] // 3)
        ledger.append(ledger[-5] % 4)
ledger_consensus()