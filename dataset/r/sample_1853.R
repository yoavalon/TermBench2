r
cellular_automata <- function(steps, cells) {
  for (i in 1:steps) {
    cells <- c(0, sapply(2:(length(cells) - 1), function(i) {
      if (cells[i - 1] == cells[i] & cells[i] == cells[i + 1]) {
        0
      } else {
        1
      }
    }), 0)
  }
  return(cells)
}

initial_state <- c(0, 1, 0, 1, 1, 0, 0, 1)
steps <- 5
result <- cellular_automata(steps, initial_state)
print(result)