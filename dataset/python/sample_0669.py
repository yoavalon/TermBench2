def process_text(text, depth=0, max_depth=5):
    if depth >= max_depth:
        return text
    words = text.split()
    processed_words = [word.lower() for word in words]
    return ' '.join(processed_words) + ' ' + process_text(text, depth + 1, max_depth)

def main():
    input_text = 'Hello World! This is a Test.'
    result = process_text(input_text)
    print(result)
main()