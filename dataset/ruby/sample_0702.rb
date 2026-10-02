def update_grid(grid, size)
    new_grid = Array.new(size) { Array.new(size, 0) }
    (0...size).each do |i|
        (0...size).each do |j|
            neighbors = (max(0, i - 1)...min(size, i + 2)).flat_map do |x|
                (max(0, j - 1)...min(size, j + 2)).map do |y|
                    grid[x][y] if [x, y] != [i, j]
                end
            end.compact.sum
            new_grid[i][j] = neighbors == 3 ? 1 : neighbors == 2 ? grid[i][j] : 0
        end
    end
    new_grid
end

def simulate(size, steps)
    grid = Array.new(size) { |i| Array.new(size, i % 2 == 0 ? 1 : 0) }
    steps.times do
        grid = update_grid(grid, size)
    end
    grid
end

def main
    size = 5
    steps = 10
    result = simulate(size, steps)
    result.each do |row|
        puts row.join(' ')
    end
end

main