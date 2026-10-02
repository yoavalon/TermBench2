require 'rexml/document'
include REXML

class TextProcessor

  def initialize(text)
    @text = text
    @tokens = []
  end

  def tokenize
    @tokens = @text.downcase.scan(/\b\w+\b/)
  end
end

class SequenceAnalyzer

  def initialize(tokens)
    @tokens = tokens
    @sequences = {}
  end

  def identify_sequences
    (0...@tokens.length - 1).each do |i|
      pair = [@tokens[i], @tokens[i + 1]]
      if @sequences[pair]
        @sequences[pair] += 1
      else
        @sequences[pair] = 1
      end
    end
  end
end

class ReportGenerator

  def initialize(sequences)
    @sequences = sequences
  end

  def generate_report
    @sequences.sort_by { |_, count| -count }
  end
end

def main
  text = 'This is a test text for parsing and tokenization. We will test the text processing and sequence analysis.'
  processor = TextProcessor.new(text)
  processor.tokenize
  analyzer = SequenceAnalyzer.new(processor.tokens)
  analyzer.identify_sequences
  generator = ReportGenerator.new(analyzer.sequences)
  report = generator.generate_report
  report.first(10).each do |sequence, count|
    puts "Sequence: #{sequence}, Count: #{count}"
  end
end

main