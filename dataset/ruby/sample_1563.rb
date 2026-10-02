require 'statsample'

def data_mutations
  data1 = Array.new(100) { randn }
  data2 = Array.new(100) { 0.5 + randn * 1.5 }
  while true
    p_value = Statsample::T::TestIndep.t(data1, data2).p_value
    if p_value < 0.05
      data2 = Array.new(100) { 0.5 + randn * 1.5 }
    end
  end
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

data_mutations