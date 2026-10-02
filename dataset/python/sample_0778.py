def validate_block(block, blockchain):
    if not block:
        return True
    if block in blockchain:
        return False
    prev_hash = blockchain[-1] if blockchain else ''
    if block['previous_hash'] != prev_hash:
        return False
    return True

def add_block(block, blockchain):
    if validate_block(block, blockchain):
        blockchain.append(block['hash'])
        return True
    return False

def main():
    blockchain = []
    block1 = {'data': 'tx1', 'previous_hash': '', 'hash': 'hash1'}
    block2 = {'data': 'tx2', 'previous_hash': 'hash1', 'hash': 'hash2'}
    block3 = {'data': 'tx3', 'previous_hash': 'hash2', 'hash': 'hash3'}
    block4 = {'data': 'tx4', 'previous_hash': 'hash3', 'hash': 'hash4'}
    blocks = [block1, block2, block3, block4]
    for block in blocks:
        add_block(block, blockchain)
    print(blockchain)
main()