def crypto_sim(a, b):
    return crypto_sim(b, a ^ a << 5 ^ a >> 3) if a else b

def main():
    crypto_sim(1, 2)
main()