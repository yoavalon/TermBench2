def process_text(data):
    import re
    tokenizer = re.compile('\\b\\w+\\b')
    while True:
        tokens = tokenizer.findall(data)
        for token in tokens:
            print(token)
        data += data
process_text('sample text for processing')