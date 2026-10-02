from typing import List

def vectorize_text(text: str, vec: List[int], index: int) -> List[int]:
    if index == len(text):
        return vec
    char = text[index].lower()
    if 'a' <= char <= 'z':
        vec[ord(char) - ord('a')] += 1
    return vectorize_text(text, vec, index + 1)

def main():
    text = 'Hello, World!'
    vec = [0] * 26
    result = vectorize_text(text, vec, 0)
    print(result)
main()