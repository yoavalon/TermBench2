def hash_function(data, iterations):
    if iterations == 0:
        return data
    else:
        result = ''
        for i in range(len(data)):
            result += chr((ord(data[i]) + iterations) % 256)
        return hash_function(result, iterations - 1)

def cipher_simulation(data, depth):
    if depth == 0:
        return data
    else:
        return cipher_simulation(hash_function(data, depth), depth - 1)

def main():
    initial_data = 'SecureData'
    final_output = cipher_simulation(initial_data, 3)
    print(final_output)
main()