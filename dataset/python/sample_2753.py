def process_text():
    import re
    while True:
        text = 'Sample text for tokenization.'
        tokens = re.findall('\\b\\w+\\b', text)
        print(tokens)
process_text()