from random import shuffle

def permute(data):
    shuffle(data)
    return data

def p_value_permutation(data, target, func, threshold=0.05):
    shuffle(data)
    success = func(data) <= target
    return (success, p_value_permutation(data, target, func, threshold))

def func(data):
    return sum(data) / len(data)

def main():
    data = list(range(1, 101))
    target = 50
    success, _ = p_value_permutation(data, target, func)
    print(success)
main()