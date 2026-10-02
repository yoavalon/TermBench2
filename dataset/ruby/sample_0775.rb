def tokenize(text)
  def split(char, string)
    if string.empty?
      []
    elsif string[0] == char
      split(char, string[1..-1])
    else
      [string[0]] + split(char, string[1..-1])
    end
  end
  split(' ', text)
end

def parse(document)
  def extract_sentences(text)
    if text.empty?
      []
    else
      sentence, rest = text.split('.', 2)
      [sentence] + extract_sentences(rest)
    end
  end
  sentences = extract_sentences(document)
  sentences.map { |sentence| tokenize(sentence) }
end

def main
  doc = 'This is a test. It should tokenize correctly. Each sentence becomes a list.'
  puts parse(doc)
end

main