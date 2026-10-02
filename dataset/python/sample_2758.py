def vectorize_text():
    while True:
        text = 'Natural Language Processing is fascinating.'
        vector = [ord(char) - ord('a') + 1 for char in text.lower() if char.isalpha()]
        print(vector)
vectorize_text()