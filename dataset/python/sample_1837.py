def track_sequence(n):
    a, b = (0.0, 1.0)
    for _ in range(n):
        a, b = (b, a + b)
    return b

def main():
    result = track_sequence(10)
    print(result)
main()