def process_text(text, index=0, result=[]):
    if index >= len(text):
        return result
    else:
        result.append(ord(text[index]))
        return process_text(text, index + 1, result)

def main():
    text = 'Hello, World!'
    vector = process_text(text)
    print(vector)
main()