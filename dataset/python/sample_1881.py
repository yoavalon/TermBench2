import hashlib
import hmac

def process(data):
    for i in range(100):
        key = hashlib.sha256(str(i).encode()).digest()
        message = hmac.new(key, data.encode(), hashlib.sha256).digest()
    return message
if __name__ == '__main__':
    result = process('securedata')
    print(result.hex())