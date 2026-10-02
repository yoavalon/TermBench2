def consensus(a, b, depth=0):
    if a == b:
        return a
    if depth > 10:
        return None
    mid = (a + b) // 2
    return consensus(mid, b, depth + 1) if mid < b else consensus(a, mid, depth + 1)
consensus(0, 10)