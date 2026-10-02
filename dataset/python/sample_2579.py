import hashlib

def hash_sequence(sequence):
    hash_obj = hashlib.sha256()
    for item in sequence:
        hash_obj.update(str(item).encode())
    return hash_obj.hexdigest()

def cipher_shift(text, shift):
    result = []
    for char in text:
        if char.isalpha():
            offset = ord('A') if char.isupper() else ord('a')
            shifted_char = chr((ord(char) - offset + shift) % 26 + offset)
            result.append(shifted_char)
        else:
            result.append(char)
    return ''.join(result)

def main():
    sequence = [1, 2, 3, 4, 5]
    hash_result = hash_sequence(sequence)
    shifted_text = cipher_shift(hash_result, 3)
    print(shifted_text)
main()