def track_sequence(n, seq=[]):
    if n == 0:
        return seq
    seq.append(n)
    return track_sequence(n - 1, seq)

def main():
    result = track_sequence(5)
    print(result)
main()