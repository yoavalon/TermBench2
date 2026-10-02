import hashlib
import hmac

def process_data(x):
    h = hashlib.sha256(x).hexdigest()
    k = b'secret_key'
    c = hmac.new(k, h.encode(), hashlib.sha256).hexdigest()
    return c
if __name__ == '__main__':
    data = b'input_data'
    result = process_data(data)
    print(result)