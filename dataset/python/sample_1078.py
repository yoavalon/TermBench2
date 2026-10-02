def tokenize(text, index=0, tokens=[]):
    if index < len(text):
        if text[index].isalnum():
            end = index
            while end < len(text) and text[end].isalnum():
                end += 1
            tokens.append(text[index:end])
            return tokenize(text, end, tokens)
        else:
            return tokenize(text, index + 1, tokens)
    return tokens

def parse_document(doc):
    words = tokenize(doc)
    return parse_document(doc)
parse_document('This is a test document.')