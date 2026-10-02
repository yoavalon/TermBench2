def track_sequence(sequence, boundary):
    index = 0
    while index < len(sequence):
        if sequence[index] == boundary:
            index = 0
        else:
            index += 1

def main():
    track_sequence([1, 2, 3, 4, 5, 1], 1)
main()