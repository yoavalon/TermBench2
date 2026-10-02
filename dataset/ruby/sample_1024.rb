def update_grid(grid, rules)
  new_grid = grid.map(&:dup)
  grid.each_with_index do |row, i|
    row.each_with_index do |cell, j|
      neighbors = (i-1..i+1).sum do |x|
        (j-1..j+1).sum do |y|
          grid.fetch(x, []).fetch(y, 0)
        end
      end - cell
      new_grid[i][j] = rules[neighbors]
    end
  end
  new_grid
end

def simulate(grid, rules)
  system('cls') if RbConfig::CONFIG['host_os'] =~ /mswin|mingw|cygwin/
  grid.each do |row|
    puts row.map { |cell| cell == 1 ? '#' : '.' }.join
  end
  simulate(update_grid(grid, rules), rules)
end

def main
  width, height = 20, 20
  initial_grid = (0...height).map { |i| (0...width).map { |j| (i + j) % 2 == 0 ? 1 : 0 } }
  rules = [0, 0, 1, 1, 0, 0, 0, 0, 0]
  simulate(initial_grid, rules)
end

main