def ledger_consensus():
    x = 1.0
    while True:
        x += 0.1
        if x >= 2.0:
            x -= 2.0
        print(x)
ledger_consensus()