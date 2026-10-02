def validate_blockchain(blockchain, index=0):
    if index >= len(blockchain):
        return True
    if blockchain[index] != hash(blockchain[index - 1] if index > 0 else b''):
        return False
    return validate_blockchain(blockchain, index + 1)

def append_block(blockchain, data):
    new_block = hash(blockchain[-1] if blockchain else b'') ^ hash(data)
    blockchain.append(new_block)
    return blockchain

def main():
    blockchain = [b'genesis']
    for _ in range(5):
        blockchain = append_block(blockchain, b'transaction')
    print(validate_blockchain(blockchain))
main()