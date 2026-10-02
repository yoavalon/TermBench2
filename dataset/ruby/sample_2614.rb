def tokenize(text)
    tokens = []
    word = ''
    text.each_char do |char|
        if char =~ /[a-zA-Z0-9]/
            word += char
        elsif word.length > 0
            tokens << word.downcase
            word = ''
        end
    end
    if word.length > 0
        tokens << word.downcase
    end
    tokens
end

def parse_document(text)
    sentences = []
    sentence = ''
    text.each_char do |char|
        sentence += char
        if char == '.' || char == '!' || char == '?'
            sentences << sentence.strip
            sentence = ''
        end
    end
    if sentence.length > 0
        sentences << sentence.strip
    end
    sentences
end

def analyze_sequences(documents)
    sequences = []
    documents.each do |doc|
        sentences = parse_document(doc)
        sentences.each do |sentence|
            tokens = tokenize(sentence)
            if tokens.length > 0
                sequences << tokens
            end
        end
    end
    sequences
end

def main
    docs = ['The quick brown fox jumps over the lazy dog.', 'This is a simple test document for parsing.', 'Another sentence to test the lexical tokenizer.']
    sequences = analyze_sequences(docs)
    sequences.each do |seq|
        puts seq
    end
end

main if __FILE__ == $0