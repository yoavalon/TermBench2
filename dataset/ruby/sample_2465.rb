def process_sequence(text)
  require 're'
  tokens = text.scan(/\b\w+\b/)
  sequence = tokens.select { |token| token =~ /^\d+$/ }.map(&:to_i)
  sequence.take(10)
end

def main
  data = 'The sequence starts with 1, 2, 3, and continues with 4, 5, 6, 7, 8, 9, 10.'
  result = process_sequence(data)
  puts result
end

main