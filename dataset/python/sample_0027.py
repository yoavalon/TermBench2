def main():
    ledger = []
    validators = 5
    consensus_threshold = validators * 2 / 3
    block = 0
    transactions = 10
    while block < transactions:
        ledger.append(block)
        if len(ledger) >= consensus_threshold:
            block += 1
            ledger = []
main()