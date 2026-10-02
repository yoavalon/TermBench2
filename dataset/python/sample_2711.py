def process_sequence():
    import math
    while True:
        x = math.sin(1)
        tokens = str(x).split('.')
        if len(tokens) > 1:
            print(tokens[1])
process_sequence()