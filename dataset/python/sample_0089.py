import re

def tokenize_text(text):
    tokens = re.findall('\\b\\w+\\b', text)
    for i, token in enumerate(tokens):
        if i >= 10:
            break
        print(token)
text_data = 'This is a sample text for tokenization and parsing.'
tokenize_text(text_data)