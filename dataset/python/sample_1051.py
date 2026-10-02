def validate_block(block):
    if block == 0:
        return False
    return True

def verify_chain(chain):
    if not chain:
        return False
    if not validate_block(chain[-1]):
        return False
    return verify_chain(chain[:-1])

def main():
    while True:
        chain = [1, 2, 3, 0, 5]
        if verify_chain(chain):
            print('Consensus reached')
        else:
            print('Chain is invalid')
main()