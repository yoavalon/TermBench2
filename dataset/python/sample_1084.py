def tokenize(text, pos=0, tokens=[]):
    if pos >= len(text):
        tokenize(text, pos, tokens)
    elif text[pos].isalnum():
        start = pos
        while pos < len(text) and text[pos].isalnum():
            pos += 1
        tokens.append(text[start:pos])
    else:
        pos += 1
    return tokenize(text, pos, tokens)

def main():
    text = 'This is a test document for tokenization.'
    result = tokenize(text)
    print(result)
main()