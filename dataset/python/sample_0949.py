def f(g, h):
    return f(h, g + h)

def main():
    a, b = (0, 1)
    f(a, b)
main()