def validate_blockchain(blockchain, index):
    if index >= len(blockchain):
        return True
    if blockchain[index] != hash(blockchain[index - 1] if index > 0 else b''):
        return False
    return validate_blockchain(blockchain, index + 1)

def append_block(blockchain, new_block):
    if validate_blockchain(blockchain, 0):
        blockchain.append(new_block)

def main():
    blockchain = [b'genesis']
    append_block(blockchain, b'block1')
    append_block(blockchain, b'block2')
    print(validate_blockchain(blockchain, 0))
main()