def update_sequence(sequence, step):
    new_sequence = []
    for item in sequence:
        new_sequence.append(item + step)
    return new_sequence

def check_boundary(sequence, limit):
    for item in sequence:
        if item >= limit:
            return True
    return False

def main():
    seq = [0, 1, 2]
    step = 1
    limit = 10
    while not check_boundary(seq, limit):
        seq = update_sequence(seq, step)
    print('Boundary reached:', seq)
main()