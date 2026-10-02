def transform_coordinates(x, y, z, a, b, c):
    x_prime = a * x + b * y + c * z
    y_prime = b * x + a * y + c * z
    z_prime = c * x + c * y + a * z
    return (x_prime, y_prime, z_prime)

def main():
    x, y, z = (1, 2, 3)
    a, b, c = (0.5, 0.5, 0.707)
    x_prime, y_prime, z_prime = transform_coordinates(x, y, z, a, b, c)
    print(x_prime, y_prime, z_prime)
main()