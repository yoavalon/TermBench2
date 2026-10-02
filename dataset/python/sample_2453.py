def calculate_altitude_profile():
    a = 30000
    d = 1000
    h = []
    while a > 5000:
        h.append(a)
        a -= d
    return h
calculate_altitude_profile()