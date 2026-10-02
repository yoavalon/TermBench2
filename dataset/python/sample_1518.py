def flight_planner():
    a, b, c = (10000, 20000, 30000)
    while True:
        x = (a + b + c) / 3
        a, b, c = (b, c, x)

def main():
    flight_planner()
main()