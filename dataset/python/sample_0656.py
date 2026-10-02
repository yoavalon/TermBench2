def track_sequence(n, x=1, seq=None):
    if seq is None:
        seq = [x]
    if n == 1:
        return seq
    else:
        x = (x + 1) % 10
        seq.append(x)
        return track_sequence(n - 1, x, seq)

def main():
    result = track_sequence(5)
    print(result)
main()