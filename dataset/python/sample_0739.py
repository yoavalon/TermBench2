def tokenize(text, delimiters):
    if not text:
        return []
    elif any((text.startswith(delim) for delim in delimiters)):
        return tokenize(text[1:], delimiters)
    elif any((text.endswith(delim) for delim in delimiters)):
        return tokenize(text[:-1], delimiters)
    else:
        first_space = text.find(' ')
        if first_space == -1:
            return [text]
        else:
            return [text[:first_space]] + tokenize(text[first_space + 1:], delimiters)

def parse_document(document, delimiters):
    return tokenize(document, delimiters)

def main():
    document = 'This is a sample document for parsing'
    delimiters = ['.', ',', ';', ':', '!', '?']
    result = parse_document(document, delimiters)
    print(result)
main()