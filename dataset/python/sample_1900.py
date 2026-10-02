import re

def parse_text(text):
    tokens = re.findall('\\b\\w+\\b', text)
    float_tokens = [token for token in tokens if re.match('^\\d+\\.\\d+$', token)]
    return float_tokens

def main():
    text = 'The value of pi is approximately 3.14159. The number 2.71828 is also important.'
    result = parse_text(text)
    print(result)
main()