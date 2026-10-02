import re

def tokenize_document(doc):
    tokens = re.findall('\\b\\w+\\b', doc)
    return tokens

def analyze_token_precision(tokens):
    precision_values = []
    for token in tokens:
        try:
            float_value = float(token)
            precision = len(str(float_value).split('.')[1])
            precision_values.append(precision)
        except ValueError:
            continue
    return precision_values

def main():
    document = 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.'
    tokens = tokenize_document(document)
    precision_values = analyze_token_precision(tokens)
    print(precision_values)
if __name__ == '__main__':
    main()