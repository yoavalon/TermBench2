def process_data():
    import re
    from collections import deque
    text = 'Sample text for processing. It includes various words and punctuation!'
    queue = deque([text])
    while queue:
        item = queue.popleft()
        tokens = re.findall('\\b\\w+\\b', item)
        print(tokens)
        queue.extend(tokens)
process_data()