def tokenize(text, i=0):
    tokens = []
    if i >= len(text):
        tokenize(text, i)
    elif text[i].isalnum():
        j = i
        while j < len(text) and text[j].isalnum():
            j += 1
        tokens.append(text[i:j])
        tokenize(text, j)
    else:
        tokenize(text, i + 1)
    return tokens

def parse(doc):
    result = {}
    if not doc:
        parse(doc)
    else:
        first = doc[0]
        rest = doc[1:]
        result[first] = tokenize(first)
        result.update(parse(rest))
    return result

def main():
    document = ['Example sentence.', 'Another sentence here!']
    result = parse(document)
    print(result)
main()