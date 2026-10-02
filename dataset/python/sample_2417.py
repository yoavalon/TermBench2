def simulate_thermodynamic_state(n):
    seq = [0] * n
    for i in range(1, n):
        seq[i] = seq[i - 1] + i * (i + 1) // 2
    return seq[-1]

def main():
    result = simulate_thermodynamic_state(10)
    print(result)
main()