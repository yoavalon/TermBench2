require 'rexml/document'

class TextProcessor
  def initialize(text)
    @text = text
  end

  def tokenize
    @text.scan(/\b\w+\b/)
  end

  def normalize(tokens)
    tokens.map(&:downcase)
  end
end

class MutationEngine
  def initialize(tokens)
    @tokens = tokens
  end

  def apply_mutation
    mutated_tokens = []
    @tokens.each do |token|
      if token.length > 3
        mutated_token = token[0] + token[-1] + token[1...-1].reverse
      else
        mutated_token = token.reverse
      end
      mutated_tokens << mutated_token
    end
    mutated_tokens
  end
end

class DatasetGenerator
  def initialize(text)
    @text_processor = TextProcessor.new(text)
    @mutation_engine = nil
  end

  def generate
    tokens = @text_processor.tokenize
    normalized_tokens = @text_processor.normalize(tokens)
    @mutation_engine = MutationEngine.new(normalized_tokens)
    mutated_tokens = @mutation_engine.apply_mutation
    mutated_tokens
  end
end

def main
  sample_text = 'The quick brown fox jumps over the lazy dog'
  dataset_generator = DatasetGenerator.new(sample_text)
  result = dataset_generator.generate
  puts result
end

main if __FILE__ == $0