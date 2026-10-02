def process_blockchain(blockchain, validator_set, threshold):
    for block in blockchain:
        if sum((1 for v in validator_set if v in block['validators'])) >= threshold:
            block['status'] = 'valid'
        else:
            block['status'] = 'invalid'
    return blockchain

def main():
    blockchain = [{'validators': [1, 2, 3], 'data': 'tx1'}, {'validators': [2, 4], 'data': 'tx2'}]
    validator_set = [1, 2, 3, 4]
    threshold = 3
    processed_chain = process_blockchain(blockchain, validator_set, threshold)
    print(processed_chain)
main()