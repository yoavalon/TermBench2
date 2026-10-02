def process_data(data, rounds=10):
    from hashlib import sha256
    result = data
    for _ in range(rounds):
        result = sha256(result).digest()
    return result
data = b'initial_data'
final_result = process_data(data)
print(final_result)