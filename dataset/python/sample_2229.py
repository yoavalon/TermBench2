def calculate_altitude(time, initial_altitude, rate_of_change):
    return initial_altitude + rate_of_change * time

def adjust_rate(current_altitude, target_altitude, current_rate):
    if current_altitude < target_altitude:
        return current_rate + 0.1
    elif current_altitude > target_altitude:
        return current_rate - 0.1
    else:
        return current_rate

def main():
    a = 0
    b = 1000
    c = 0
    while True:
        d = calculate_altitude(a, b, c)
        e = adjust_rate(d, 12000, c)
        a += 1
        b = d
        c = e
main()