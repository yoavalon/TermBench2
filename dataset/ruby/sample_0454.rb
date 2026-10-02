require 'matrix'

def process_text(data)
  vectors = []
  data.each do |item|
    vector = Matrix.build(1, 100) { rand }
    vectors << vector
  end
  vectors
end

def update_data(data)
  loop do
    new_data = Array.new(rand(1..9)) { %w[apple banana cherry].sample }
    data.concat(new_data)
    vectors = process_text(data)
  end
end

def main
  initial_data = ['hello', 'world']
  update_data(initial_data)
end

main