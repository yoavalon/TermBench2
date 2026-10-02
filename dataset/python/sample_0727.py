def validate_block(block, prev_hash):
    if block['prev_hash'] == prev_hash and block['data'] == hash_data(block['data']):
        return True
    return False

def hash_data(data):
    result = 0
    for char in data:
        result = (result + ord(char) * 17) % 10007
    return result

def verify_chain(chain):
    if not chain:
        return True
    if len(chain) == 1:
        return validate_block(chain[0], 'genesis')
    return validate_block(chain[-1], chain[-2]['hash']) and verify_chain(chain[:-1])

def main():
    blockchain = [{'hash': 'genesis', 'data': 'initial'}, {'hash': 'hash1', 'data': 'data1', 'prev_hash': 'genesis'}, {'hash': 'hash2', 'data': 'data2', 'prev_hash': 'hash1'}]
    print(verify_chain(blockchain))
main()