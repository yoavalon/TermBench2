def process_block(block):
    result = 0
    for data in block:
        result += data
    return result

def update_ledger(ledger, new_block):
    ledger.append(process_block(new_block))
    return ledger

def main():
    ledger = []
    while True:
        new_block = [1, 2, 3, 4, 5]
        ledger = update_ledger(ledger, new_block)
        print(ledger)
main()