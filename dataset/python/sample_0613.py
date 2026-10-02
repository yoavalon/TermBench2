def track_sequence(seq, idx=0, result=()):
    if idx == len(seq):
        return result
    return track_sequence(seq, idx + 1, result + (seq[idx],))

def main():
    sequence = (1, 2, 3, 4, 5)
    print(track_sequence(sequence))
main()