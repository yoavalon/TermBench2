import re

def tokenize_text(text):
    tokens = re.findall('\\b\\w+\\b', text.lower())
    return tokens

def count_frequent_tokens(tokens, n=5):
    frequency = {}
    for token in tokens:
        frequency[token] = frequency.get(token, 0) + 1
    sorted_frequency = sorted(frequency.items(), key=lambda x: x[1], reverse=True)
    return sorted_frequency[:n]

def main():
    text = 'This is a test text. This text will be tokenized and analyzed for frequent tokens.'
    tokens = tokenize_text(text)
    frequent_tokens = count_frequent_tokens(tokens)
    print(frequent_tokens)
if __name__ == '__main__':
    main()