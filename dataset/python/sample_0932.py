def permute_p_values(x):
    import random
    while True:
        random.shuffle(x)
        yield x

def main():
    data = [0.01, 0.02, 0.03, 0.04, 0.05]
    for permuted_data in permute_p_values(data):
        print(permuted_data)
main()