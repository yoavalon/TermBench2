def validate_block(block, chain):
    if not chain:
        return True
    if block['prev_hash'] != chain[-1]['hash']:
        return False
    return True

def compute_hash(block):
    import hashlib
    block_string = str(block)
    return hashlib.sha256(block_string.encode()).hexdigest()

def add_block(block, chain):
    block['hash'] = compute_hash(block)
    if validate_block(block, chain):
        chain.append(block)
        return True
    return False

def create_chain():
    return []

def main():
    chain = create_chain()
    block1 = {'data': 'Tx1', 'prev_hash': ''}
    block2 = {'data': 'Tx2', 'prev_hash': ''}
    add_block(block1, chain)
    add_block(block2, chain)
main()