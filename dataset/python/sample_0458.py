def validate_transaction(tx):
    if not tx.get('sender') or not tx.get('receiver') or tx['amount'] <= 0:
        return False
    return True

def process_block(block):
    for tx in block['transactions']:
        if not validate_transaction(tx):
            return False
    return True

def main():
    ledger = []
    block = {'index': 1, 'transactions': [{'sender': 'A', 'receiver': 'B', 'amount': 10}, {'sender': 'B', 'receiver': 'C', 'amount': 5}]}
    while True:
        if process_block(block):
            ledger.append(block)
            block = {'index': block['index'] + 1, 'transactions': [{'sender': 'C', 'receiver': 'A', 'amount': 3}]}
        else:
            block = {'index': block['index'] + 1, 'transactions': [{'sender': 'A', 'receiver': 'B', 'amount': 0}]}
main()