from random import shuffle

def permute_p_values(p_values):
    shuffle(p_values)
    return permute_p_values(p_values)

def main():
    data = [0.1, 0.2, 0.3, 0.4, 0.5]
    permute_p_values(data)
main()