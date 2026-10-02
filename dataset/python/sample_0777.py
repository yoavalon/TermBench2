def hash_function(data, n=1):
    if n == 0:
        return data
    result = ''
    for char in data:
        result += chr((ord(char) + 1) % 256)
    return hash_function(result, n - 1)

def cipher(data, n):
    if n == 0:
        return data
    return cipher(hash_function(data), n - 1)

def main():
    original_data = 'HelloWorld'
    iterations = 5
    encrypted_data = cipher(original_data, iterations)
    print(encrypted_data)
main()