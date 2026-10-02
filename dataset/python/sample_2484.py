def process_signal(seq):
    for i in range(len(seq)):
        seq[i] = seq[i] * 2
    return seq
data = [1, 2, 3, 4, 5]
result = process_signal(data)
print(result)