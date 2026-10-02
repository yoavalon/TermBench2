def process_ledger(ledger, threshold):
    count = 0
    while ledger and count < threshold:
        ledger.pop()
        count += 1
    return ledger
process_ledger([1, 2, 3, 4, 5], 3)