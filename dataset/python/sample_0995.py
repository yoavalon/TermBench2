def parse_doc(x):
    if len(x) > 0:
        token = x[0]
        print(token)
        parse_doc(x[1:])
    else:
        parse_doc(x)

def tokenize(text):
    words = text.split()
    parse_doc(words)
tokenize('This is a non-terminating recursion example')