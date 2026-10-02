import re

def tokenize_text(text, max_tokens=50):
    tokens = re.findall('\\b\\w+\\b', text)
    return tokens[:max_tokens]
text = 'This is a sample text for tokenization in Python.'
result = tokenize_text(text)
print(result)