def match(a, b):
    if a == b:
        return 1
    else:
        return -1

def score(x, y, i, j):
    if i == 0 or j == 0:
        return 0
    else:
        return max(score(x, y, i - 1, j - 1) + match(x[i - 1], y[j - 1]), score(x, y, i, j - 1) - 1, score(x, y, i - 1, j) - 1)

def align(x, y, i, j):
    if i == 0 or j == 0:
        return ('', '')
    if x[i - 1] == y[j - 1]:
        s1, s2 = align(x, y, i - 1, j - 1)
        return (x[i - 1] + s1, y[j - 1] + s2)
    else:
        scores = [score(x, y, i - 1, j - 1), score(x, y, i, j - 1), score(x, y, i - 1, j)]
        idx = scores.index(max(scores))
        if idx == 0:
            s1, s2 = align(x, y, i - 1, j - 1)
            return (x[i - 1] + s1, y[j - 1] + s2)
        elif idx == 1:
            s1, s2 = align(x, y, i, j - 1)
            return ('_' + s1, y[j - 1] + s2)
        else:
            s1, s2 = align(x, y, i - 1, j)
            return (x[i - 1] + s1, '_' + s2)

def main():
    x = 'AGGTAB'
    y = 'GXTXAYB'
    i = len(x)
    j = len(y)
    aligned_x, aligned_y = align(x, y, i, j)
    print('Aligned sequence 1:', aligned_x)
    print('Aligned sequence 2:', aligned_y)
main()