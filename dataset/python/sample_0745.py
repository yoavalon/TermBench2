import numpy as np

def permute(data, index, result, results):
    if index == len(data):
        results.append(result[:])
    else:
        for i in range(len(data)):
            if data[i] not in result:
                result.append(data[i])
                permute(data, index + 1, result, results)
                result.pop()

def calculate_pvalue(data1, data2):
    combined = np.concatenate((data1, data2))
    original_mean_diff = np.mean(data1) - np.mean(data2)
    count_greater = 0
    permutations = []
    permute(combined, 0, [], permutations)
    for perm in permutations:
        perm1 = perm[:len(data1)]
        perm2 = perm[len(data1):]
        if np.mean(perm1) - np.mean(perm2) >= original_mean_diff:
            count_greater += 1
    return count_greater / len(permutations)

def main():
    data1 = np.array([1, 2, 3, 4])
    data2 = np.array([5, 6, 7, 8])
    pvalue = calculate_pvalue(data1, data2)
    print(pvalue)
main()