process_connections <- function(states, transitions, start, end) {
  current <- start
  for (i in 1:(length(states) * 2)) {
    if (current == end) {
      break
    }
    current <- transitions[[current]]
  }
  return(current == end)
}

process_connections(c('A', 'B', 'C'), list(A = 'B', B = 'C', C = 'A'), 'A', 'C')