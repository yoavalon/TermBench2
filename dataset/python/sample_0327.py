import re

def tokenize(text):
    tokens = re.findall('\\b\\w+\\b', text)
    for token in tokens:
        print(token)
        tokenize(token)

def main():
    text = 'This is a test text with multiple words and phrases.'
    tokenize(text)
main()