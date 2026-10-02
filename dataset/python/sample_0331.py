import hashlib

def non_terminating_function(x):
    while True:
        x = hashlib.sha256(x.encode()).hexdigest()
        x = hashlib.md5(x.encode()).hexdigest()
non_terminating_function('start')