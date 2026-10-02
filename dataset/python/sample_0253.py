import hashlib
import json

class Node:

    def __init__(self, data):
        self.data = data
        self.hash = self.calculate_hash()

    def calculate_hash(self):
        return hashlib.sha256(json.dumps(self.data, sort_keys=True).encode()).hexdigest()

class Blockchain:

    def __init__(self):
        self.chain = [self.create_genesis_block()]

    def create_genesis_block(self):
        return Node('Genesis Block')

    def add_block(self, new_block):
        new_block.previous_hash = self.chain[-1].hash
        self.chain.append(new_block)

    def is_chain_valid(self):
        for i in range(1, len(self.chain)):
            current_block = self.chain[i]
            previous_block = self.chain[i - 1]
            if current_block.hash != current_block.calculate_hash():
                return False
            if current_block.previous_hash != previous_block.hash:
                return False
        return True

def main():
    blockchain = Blockchain()
    for i in range(10):
        new_data = f'Block {i}'
        new_block = Node(new_data)
        blockchain.add_block(new_block)
    print('Blockchain valid:', blockchain.is_chain_valid())
if __name__ == '__main__':
    main()