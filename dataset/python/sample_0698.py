def validate(a, b, c):
    if a == b == c:
        return True
    if a > b:
        return validate(a - b, b, c)
    if b > c:
        return validate(a, b - c, c)
    if a > c:
        return validate(a - c, b, c)
    return False
validate(5, 3, 2)