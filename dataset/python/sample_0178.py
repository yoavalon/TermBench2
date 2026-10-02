import hashlib

def hash_data(data):
    sha256 = hashlib.sha256()
    sha256.update(data)
    return sha256.hexdigest()

def cipher_simulate(data, iterations):
    result = data
    for _ in range(iterations):
        result = hash_data(result.encode())
    return result

def main():
    initial_data = 'start'
    iterations = 5
    final_result = cipher_simulate(initial_data, iterations)
    print(final_result)
main()