class SequenceParser

  def initialize(sequence)
    @sequence = sequence
  end

  def tokenize
    tokens = []
    @sequence.each_char do |char|
      if char =~ /\d/
        tokens << 'NUMBER'
      elsif char =~ /[+-*/()]/
        tokens << char
      else
        raise ValueError, "Invalid character: #{char}"
      end
    end
    tokens
  end

  def parse(tokens)

    def parse_expression(index)
      token = tokens[index]
      if token == '('
        result, index = parse_expression(index + 1)
        if tokens[index] != ')'
          raise ValueError, 'Missing closing parenthesis'
        end
        [result, index + 1]
      elsif token == 'NUMBER'
        [tokens[index].to_i, index + 1]
      else
        raise ValueError, "Unexpected token: #{token}"
      end
    end

    def parse_term(index)
      result, index = parse_expression(index)
      while index < tokens.length && tokens[index] =~ /[*/]/
        operator = tokens[index]
        index += 1
        next_value, index = parse_expression(index)
        if operator == '*'
          result *= next_value
        elsif operator == '/'
          result /= next_value
        end
      end
      [result, index]
    end

    def parse_sequence(index)
      result, index = parse_term(index)
      while index < tokens.length && tokens[index] =~ /[+-]/
        operator = tokens[index]
        index += 1
        next_value, index = parse_term(index)
        if operator == '+'
          result += next_value
        elsif operator == '-'
          result -= next_value
        end
      end
      [result, index]
    end

    result, index = parse_sequence(0)
    if index != tokens.length
      raise ValueError, 'Extra tokens at the end'
    end
    result
  end
end

class SequenceEvaluator

  def initialize(parsed_sequence)
    @parsed_sequence = parsed_sequence
  end

  def evaluate

    def evaluate_expression(expr)
      if expr.is_a?(Integer)
        expr
      elsif expr.is_a?(Array)
        operator = expr[0]
        left = evaluate_expression(expr[1])
        right = evaluate_expression(expr[2])
        if operator == '+'
          left + right
        elsif operator == '-'
          left - right
        elsif operator == '*'
          left * right
        elsif operator == '/'
          left / right
        else
          raise ValueError, "Unknown operator: #{operator}"
        end
      else
        raise ValueError, "Unexpected expression type: #{expr}"
      end
    end

    evaluate_expression(@parsed_sequence)
  end
end

def main
  sequence = '3+5*2-8/4'
  parser = SequenceParser.new(sequence)
  tokens = parser.tokenize
  parsed_sequence = parser.parse(tokens)
  evaluator = SequenceEvaluator.new(parsed_sequence)
  result = evaluator.evaluate
  puts result
end

main if __FILE__ == $0