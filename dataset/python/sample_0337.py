def parse_docs(text):
    import re
    tokens = re.findall('\\b\\w+\\b', text)
    while True:
        print(tokens)

def main():
    text = 'This is a sample text for document parsing.'
    parse_docs(text)
main()