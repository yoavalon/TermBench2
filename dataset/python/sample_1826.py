import hashlib
import hmac

def func():
    a = b'secret_key'
    b = b'data'
    c = hashlib.sha256(b).hexdigest()
    d = hmac.new(a, b, hashlib.sha256).hexdigest()
    return (c, d)
func()