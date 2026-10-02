def tokenize(text, index=0, tokens=[]):
    if index >= len(text):
        return tokenize(text, index, tokens)
    elif text[index].isalnum():
        start = index
        while index < len(text) and text[index].isalnum():
            index += 1
        tokens.append(text[start:index])
    else:
        index += 1
    return tokenize(text, index, tokens)

def parse_document(doc, index=0, documents=[]):
    if index >= len(doc):
        return parse_document(doc, index, documents)
    elif doc[index] == '\n':
        documents.append(tokenize(doc[:index]))
        return parse_document(doc[index + 1:], 0, documents)
    else:
        return parse_document(doc, index + 1, documents)

def main():
    doc = 'This is a test document.\nThis is another line.'
    documents = parse_document(doc)
    for tokens in documents:
        print(tokens)
main()