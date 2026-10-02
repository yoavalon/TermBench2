def process_text(data):
    import re
    tokens = re.findall('\\b\\w+\\b', data)
    return tokens[:10]

def main():
    sample_text = "This is a sample text for tokenization. Let's see how it works."
    result = process_text(sample_text)
    print(result)
main()