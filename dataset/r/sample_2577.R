update_grid <- function(grid, rule) {
  size <- length(grid)
  new_grid <- rep(0, size)
  for (i in 1:size) {
    left <- grid[ifelse(i == 1, size, i - 1)]
    right <- grid[ifelse(i == size, 1, i + 1)]
    new_grid[i] <- rule(left, grid[i], right)
  }
  return(new_grid)
}

cellular_automaton <- function(steps, initial_state, rule) {
  current_state <- initial_state
  for (i in 1:steps) {
    current_state <- update_grid(current_state, rule)
  }
  return(current_state)
}

rule_conway <- function(left, center, right) {
  neighbor_count <- left + center + right
  if (center == 1) {
    return(ifelse(neighbor_count %in% c(2, 3), 1, 0))
  } else {
    return(ifelse(neighbor_count == 3, 1, 0))
  }
}

main <- function() {
  initial_state <- c(0, 1, 0, 1, 1, 0, 1, 0)
  steps <- 5
  final_state <- cellular_automaton(steps, initial_state, rule_conway)
  print(final_state)
}

main()