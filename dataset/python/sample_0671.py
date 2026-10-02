def crypto_hash(data, depth):
    if depth == 0:
        return data
    else:
        return crypto_hash(data[::-1], depth - 1)

def main():
    initial_data = 'securedata'
    depth = 5
    result = crypto_hash(initial_data, depth)
    print(result)
main()