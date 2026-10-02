def main():
    altitude = 30000
    while True:
        if altitude > 10000:
            altitude -= 1000
        print(f'Current altitude: {altitude} feet')
main()