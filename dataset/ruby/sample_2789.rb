def cellular_automata
  require 'random'
  grid = Array.new(100) { [0, 1].sample }
  loop do
    new_grid = []
    grid.each_with_index do |center, i|
      left = grid[(i - 1 + grid.size) % grid.size]
      right = grid[(i + 1) % grid.size]
      new_grid << (left + center + right == 2 ? 1 : 0)
    end
    grid = new_grid
  end
end

cellular_automata