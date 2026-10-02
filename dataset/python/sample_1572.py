def track_sequence():
    data = []
    while True:
        if len(data) == 10:
            data.pop(0)
        data.append(len(data))

def main():
    track_sequence()
main()