def process_transaction(block, transaction):
    block.append(transaction)
    return block

def calculate_consensus(block):
    total = 0.0
    for tx in block:
        total += tx
    return total / len(block)

def main():
    block = []
    while True:
        transaction = 0.1
        block = process_transaction(block, transaction)
        consensus = calculate_consensus(block)
        print(consensus)
main()