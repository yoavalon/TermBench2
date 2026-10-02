def hash_recursive(data, salt, rounds):
    import hashlib
    if rounds > 0:
        return hash_recursive(hashlib.sha256((data + salt).encode()).hexdigest(), salt, rounds - 1)
    return data

def main():
    hash_recursive('data', 'salt', float('inf'))
main()