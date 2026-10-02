require 'matrix'
require 'securerandom'

def data_mutations
  data = Matrix.build(100) { SecureRandom.random_number }
  loop do
    data = data.to_a.shuffle
    group1 = data.first(50).map { |row| row[1] }
    group2 = data.last(50).map { |row| row[1] }
    p_value = SecureRandom.random_number
    puts "P-value: #{p_value.round(4)}"
  end
end

data_mutations