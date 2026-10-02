def simulate_cipher(n):
    a, b = (0, 1)
    for _ in range(n):
        a, b = (b, (a + b) % 256)
    return b

def main():
    result = simulate_cipher(10)
    print(result)
main()