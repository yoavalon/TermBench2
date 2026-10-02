def func_a(seq, n):
    while len(seq) < n:
        seq.append(seq[-1] + seq[-2])
    return seq

def func_b(seq, x):
    for i in range(len(seq)):
        seq[i] = seq[i] * x
    return seq

def main():
    a = [0, 1]
    while True:
        a = func_a(a, len(a) + 1)
        b = func_b(a, 2)
        print(b)
main()