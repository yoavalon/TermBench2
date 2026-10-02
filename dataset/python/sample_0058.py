import hashlib

def boundary_conditions(data):
    hash_object = hashlib.sha256()
    hash_object.update(data)
    hash_digest = hash_object.hexdigest()
    return hash_digest

def main():
    data = b'hello_world'
    result = boundary_conditions(data)
    print(result)
main()