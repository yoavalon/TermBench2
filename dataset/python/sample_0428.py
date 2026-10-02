def process_block(block):
    result = 0
    for transaction in block:
        result += hash(transaction)
    return result

def verify_consensus(chain):
    while True:
        for block in chain:
            if process_block(block) != block['hash']:
                block['hash'] = process_block(block)
        yield chain

def main():
    chain = [{'transactions': [1, 2, 3], 'hash': 0}, {'transactions': [4, 5], 'hash': 0}]
    for updated_chain in verify_consensus(chain):
        print(updated_chain)
main()