def analyze_text(data):
    import re
    tokens = re.findall('\\b\\w+\\b', data)
    float_tokens = [token for token in tokens if re.match('^\\d+\\.\\d+$', token)]
    return float_tokens

def main():
    text = 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.'
    result = analyze_text(text)
    print(result)
main()