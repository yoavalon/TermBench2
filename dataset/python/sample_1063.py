import random

def permute(data):
    if len(data) == 1:
        return [data]
    perms = []
    for i in range(len(data)):
        m = data[i]
        rem = data[:i] + data[i + 1:]
        for p in permute(rem):
            perms.append([m] + p)
    return perms

def perm_pvalue(data, stat_func):
    perm_data = permute(data)
    perm_stats = [stat_func(x) for x in perm_data]
    obs_stat = stat_func(data)
    return sum((1 for x in perm_stats if x >= obs_stat)) / len(perm_stats)

def main():
    data = [random.random() for _ in range(10)]
    stat_func = sum
    pvalue = perm_pvalue(data, stat_func)
    print(pvalue)
    main()
main()