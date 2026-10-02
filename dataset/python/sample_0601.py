def consensus(a, b, depth=0):
    if a == b or depth > 10:
        return a
    mid = (a + b) // 2
    return consensus(mid, b, depth + 1) if mid > a else consensus(a, mid, depth + 1)
consensus(1, 10)