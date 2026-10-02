def process_sequence(data):
    import hashlib
    result = []
    for i in range(len(data)):
        hash_object = hashlib.sha256(str(data[i]).encode())
        result.append(int(hash_object.hexdigest(), 16) % 1000)
    return result
if __name__ == '__main__':
    data = [1, 2, 3, 4, 5]
    print(process_sequence(data))