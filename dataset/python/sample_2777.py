def math_seq_parser(text):
    while True:
        words = text.split()
        for word in words:
            try:
                num = int(word)
                print(num * num)
            except ValueError:
                continue
math_seq_parser('1 2 three 4 five 6')