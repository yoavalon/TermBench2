def precision_loss_calculation(a, b):
    x = a + b
    y = a - b
    return (x, y)

def consensus_mechanics(a, b):
    x, y = precision_loss_calculation(a, b)
    z = x * y
    w = z / a
    return w

def main():
    a = 1.0000001
    b = 2e-07
    result = consensus_mechanics(a, b)
    print(result)
main()