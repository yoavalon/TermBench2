def plan_flight():
    a = 30000
    b = 1000
    while True:
        c = a - b
        if c > 10000:
            a = c
        else:
            a += 500

def main():
    plan_flight()
main()