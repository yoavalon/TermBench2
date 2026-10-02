require 'statistics2'

def data_mutations
  loop do
    a = Array.new(100) { randn }
    b = Array.new(100) { randn }
    p_value = Statistics2::TTest.new(a, b).p
    puts p_value
  end
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

data_mutations