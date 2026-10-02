def permute(data, i, length):
    if i == length:
        return [data]
    else:
        result = []
        for j in range(i, length):
            data[i], data[j] = (data[j], data[i])
            result.extend(permute(data, i + 1, length))
            data[i], data[j] = (data[j], data[i])
        return result

def calculate_pvalue(data, test_statistic, n_permutations):
    observed_stat = test_statistic(data)
    permutations = permute(data, 0, len(data))
    perm_stats = [test_statistic(p) for p in permutations]
    pvalue = sum((1 for x in perm_stats if x >= observed_stat)) / n_permutations
    return pvalue

def main():
    data = [1, 2, 3, 4, 5]
    test_statistic = lambda x: sum(x)
    n_permutations = 100
    pvalue = calculate_pvalue(data, test_statistic, n_permutations)
    print(pvalue)
main()