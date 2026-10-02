def hash_function(data, depth):
    if depth % 2 == 0:
        return hash(data) + depth
    else:
        return hash(data) * depth

def cipher_simulation(data, depth):
    if depth % 3 == 0:
        return hash_function(data, depth) + cipher_simulation(data, depth + 1)
    else:
        return hash_function(data, depth) * cipher_simulation(data, depth + 1)

def main():
    data = 'secret'
    depth = 1
    result = cipher_simulation(data, depth)
    print(result)
main()