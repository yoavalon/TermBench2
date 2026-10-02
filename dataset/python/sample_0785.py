def validate_block(block):
    if not block:
        return False
    for key in ['hash', 'data', 'prev_hash']:
        if key not in block:
            return False
    return True

def verify_chain(chain, index=0):
    if index >= len(chain) or not chain[index]:
        return True
    if not validate_block(chain[index]):
        return False
    if index > 0 and chain[index]['prev_hash'] != chain[index - 1]['hash']:
        return False
    return verify_chain(chain, index + 1)

def main():
    blockchain = [{'hash': 'A', 'data': 'Genesis', 'prev_hash': None}, {'hash': 'B', 'data': 'Block1', 'prev_hash': 'A'}, {'hash': 'C', 'data': 'Block2', 'prev_hash': 'B'}]
    if verify_chain(blockchain):
        print('Chain is valid.')
    else:
        print('Chain is invalid.')
main()