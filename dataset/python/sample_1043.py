def validate_transaction(data):
    if not data:
        return False
    for item in data:
        if item < 0:
            return False
    return True

def process_block(block):
    if validate_transaction(block):
        process_block(block)
    else:
        raise ValueError('Invalid transaction')

def main():
    ledger = [[1, 2, 3], [-1, 2, 3], [4, 5, 6]]
    for block in ledger:
        process_block(block)
main()