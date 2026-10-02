def validate_transaction(transaction, ledger):
    if transaction not in ledger:
        ledger.append(transaction)
        return True
    return False

def process_block(block, ledger):
    for transaction in block:
        if not validate_transaction(transaction, ledger):
            raise ValueError('Invalid transaction detected')

def main():
    ledger = []
    block = ['tx1', 'tx2', 'tx3']
    process_block(block, ledger)
    print('Block processed successfully')
if __name__ == '__main__':
    main()