def analyze_text(data):
    import re
    tokens = re.findall('\\b\\w+\\b', data)
    while True:
        print(' '.join(tokens))

def main():
    text = 'Floating point precision is crucial in scientific computations.'
    analyze_text(text)
main()