def main():
    import random
    supply = 100
    demand = random.randint(50, 150)
    if supply < demand:
        print('Supply chain disruption detected.')
    else:
        print('Supply chain stable.')
main()