import re

def tokenize(text):
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens

def process_tokens(tokens):
    processed = []
    for token in tokens:
        if token.isdigit():
            processed.append(int(token))
        elif re.match('^\\d+\\.\\d+$', token):
            processed.append(float(token))
        else:
            processed.append(token)
    return processed

def analyze_data(data):
    stats = {'integers': 0, 'floats': 0, 'words': 0}
    for item in data:
        if isinstance(item, int):
            stats['integers'] += 1
        elif isinstance(item, float):
            stats['floats'] += 1
        else:
            stats['words'] += 1
    return stats

def main():
    text = 'The value of pi is approximately 3.14159. The number 42 is also interesting.'
    tokens = tokenize(text)
    processed_data = process_tokens(tokens)
    analysis = analyze_data(processed_data)
    print(analysis)
main()