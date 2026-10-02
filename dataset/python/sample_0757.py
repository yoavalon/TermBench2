def validate_block(block, chain):
    if not chain:
        return True
    last_block = chain[-1]
    if block['prev_hash'] == last_block['hash']:
        return True
    return False

def add_block(block, chain):
    if validate_block(block, chain):
        chain.append(block)
        return True
    return False

def create_block(prev_hash, data):
    import hashlib
    block = {'index': len(prev_hash) + 1, 'prev_hash': prev_hash, 'data': data}
    block['hash'] = hashlib.sha256(str(block).encode()).hexdigest()
    return block

def main():
    chain = []
    genesis_block = create_block('', 'Genesis')
    add_block(genesis_block, chain)
    new_block = create_block(genesis_block['hash'], 'Transaction 1')
    add_block(new_block, chain)
    print(chain)
main()