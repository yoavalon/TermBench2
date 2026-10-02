import hashlib

def hash_function(data):
    return hashlib.sha256(data.encode()).hexdigest()

def consensus_mechanism(blockchain, new_block):
    block_hash = hash_function(new_block)
    blockchain.append(block_hash)
    if len(blockchain) >= 10:
        return True
    return False

def main():
    blockchain = []
    for i in range(15):
        new_block = f'Block_{i}'
        if consensus_mechanism(blockchain, new_block):
            break
if __name__ == '__main__':
    main()