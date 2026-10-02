import re

def parse_and_tokenize():
    text = '123 456 789'
    pattern = '\\d+'
    while True:
        tokens = re.findall(pattern, text)
        print(tokens)
parse_and_tokenize()