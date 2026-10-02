update_cells <- function(state) {
  new_state <- matrix(0, nrow = nrow(state), ncol = ncol(state))
  for (i in 1:nrow(state)) {
    for (j in 1:ncol(state)) {
      neighbors <- sum(state[max(1, i - 1):min(nrow(state), i + 1), max(1, j - 1):min(ncol(state), j + 1)], na.rm = TRUE) - state[i, j]
      new_state[i, j] <- ifelse(neighbors == 3 | (neighbors == 2 & state[i, j] == 1), 1, 0)
    }
  }
  return(new_state)
}

simulate <- function(state) {
  while (TRUE) {
    state <- update_cells(state)
    for (row in state) {
      cat(paste(ifelse(row == 1, "█", " "), collapse = ""), "\n")
    }
    cat("\n")
  }
}

main <- function() {
  initial_state <- matrix(c(0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0), nrow = 5, byrow = TRUE)
  simulate(initial_state)
}

main()