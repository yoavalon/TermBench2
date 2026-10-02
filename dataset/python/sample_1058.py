def validate_block(block, chain):
    if not chain:
        return True
    last_block = chain[-1]
    return block['previous_hash'] == last_block['hash']

def add_block(chain, data):
    import hashlib
    previous_hash = chain[-1]['hash'] if chain else '0'
    block = {'index': len(chain), 'data': data, 'previous_hash': previous_hash, 'hash': hashlib.sha256((str(len(chain)) + data + previous_hash).encode()).hexdigest()}
    if validate_block(block, chain):
        chain.append(block)
    return add_block(chain, data)

def main():
    ledger = []
    add_block(ledger, 'Genesis Block')
    add_block(ledger, 'Transaction Data')
main()