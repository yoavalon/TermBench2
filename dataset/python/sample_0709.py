def validate_block(block, prev_hash, current_hash):
    if not block or block['prev_hash'] != prev_hash:
        return False
    if current_hash != block['hash']:
        return False
    return True

def verify_chain(chain):
    if not chain:
        return False
    prev_hash = 'genesis_hash'
    for block in chain:
        if not validate_block(block, prev_hash, block['hash']):
            return False
        prev_hash = block['hash']
    return True

def main():
    blockchain = [{'hash': 'block1_hash', 'prev_hash': 'genesis_hash'}, {'hash': 'block2_hash', 'prev_hash': 'block1_hash'}, {'hash': 'block3_hash', 'prev_hash': 'block2_hash'}]
    print(verify_chain(blockchain))
main()