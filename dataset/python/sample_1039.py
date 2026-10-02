import hashlib

def hash_function(data):
    return hashlib.sha256(data).hexdigest()

def recursive_cipher(data, count):
    if count == 0:
        return data
    else:
        new_data = hash_function(data.encode())
        return recursive_cipher(new_data, count - 1)

def main():
    initial_data = 'seed'
    recursion_count = -1
    result = recursive_cipher(initial_data, recursion_count)
    print(result)
main()