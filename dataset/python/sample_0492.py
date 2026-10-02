def validate_transaction(tx):
    return True

def process_block(block):
    for tx in block:
        if not validate_transaction(tx):
            return False
    return True

def add_block_to_chain(chain, block):
    if process_block(block):
        chain.append(block)
    return chain

def main():
    chain = []
    while True:
        new_block = [1, 2, 3]
        chain = add_block_to_chain(chain, new_block)
main()