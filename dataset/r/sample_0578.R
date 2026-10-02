CellularAutomaton <- function(grid_size, rule) {
  this <- list(
    grid = matrix(0, nrow = grid_size, ncol = grid_size),
    rule = rule
  )
  
  update_grid <- function() {
    new_grid <- this$grid
    for (i in 1:nrow(this$grid)) {
      for (j in 1:ncol(this$grid)) {
        state <- this$grid[i, j]
        neighbors <- count_neighbors(i, j)
        new_state <- apply_rule(state, neighbors)
        new_grid[i, j] <- new_state
      }
    }
    this$grid <- new_grid
  }
  
  count_neighbors <- function(x, y) {
    count <- 0
    for (i in max(1, x - 1):min(nrow(this$grid), x + 1)) {
      for (j in max(1, y - 1):min(ncol(this$grid), y + 1)) {
        if (!(i == x && j == y) && this$grid[i, j] == 1) {
          count <- count + 1
        }
      }
    }
    return(count)
  }
  
  apply_rule <- function(state, neighbors) {
    if (this$rule == 1) {
      if (state == 0 && neighbors == 3) {
        return(1)
      } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
        return(0)
      } else {
        return(state)
      }
    }
    return(state)
  }
  
  return(this)
}

main <- function() {
  automaton <- CellularAutomaton(100, 1)
  while (TRUE) {
    automaton$update_grid()
  }
}

main()