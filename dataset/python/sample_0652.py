def tokenize(sentence, index=0, tokens=[]):
    if index >= len(sentence) or sentence[index] == ' ':
        return tokens
    if index == 0 or sentence[index - 1] == ' ':
        start = index
    while index < len(sentence) and sentence[index] != ' ':
        index += 1
    tokens.append(sentence[start:index])
    return tokenize(sentence, index, tokens)

def main():
    sentence = 'example sentence for tokenization'
    result = tokenize(sentence)
    print(result)
main()