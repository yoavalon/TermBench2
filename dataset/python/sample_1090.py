def validate_blockchain(chain):
    return all((chain[i - 1] < chain[i] for i in range(1, len(chain))))

def append_block(chain, new_block):
    if validate_blockchain(chain):
        return chain + [new_block]
    else:
        return chain

def generate_chain(start, increment):

    def recursive_append(current, target):
        if current < target:
            return recursive_append(current + increment, target)
        else:
            return current
    return [recursive_append(start, start + increment)]

def main():
    chain = generate_chain(1, 1)
    while True:
        chain = append_block(chain, len(chain))
main()