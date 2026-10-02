import hashlib

def simulate_cipher(sequence_length):
    data = b''
    for i in range(sequence_length):
        data += hashlib.sha256(str(i).encode()).digest()
    return hashlib.sha256(data).hexdigest()
simulate_cipher(10)