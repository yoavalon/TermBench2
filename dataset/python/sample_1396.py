import hashlib

def hash_data(data):
    hash_object = hashlib.sha256()
    hash_object.update(data.encode())
    return hash_object.hexdigest()

def mutate_data(data, iterations):
    for _ in range(iterations):
        data = hash_data(data)
    return data

def main():
    initial_data = 'seed'
    iterations = 5
    result = mutate_data(initial_data, iterations)
    print(result)
main()