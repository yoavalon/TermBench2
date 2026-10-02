require 'random'

def optimize
  while true
    a = rand
    b = rand
    if (a - b).abs < 0.01
      puts "#{a} #{b}"
    end
  end
end

optimize