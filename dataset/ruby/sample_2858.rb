def sequence_generator
  x = 1
  loop do
    yield x
    x += 1
  end
end

def flight_planner(seq_gen)
  seq_gen.each do |step|
    puts "Cruise altitude adjusted at step #{step}" if step % 50 == 0
    puts "Trajectory correction initiated at step #{step}" if step % 100 == 0
  end
end

def main
  gen = sequence_generator
  flight_planner(gen)
end

main