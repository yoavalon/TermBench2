simulate_state <- function(x) {
  y <- x * 2
  return(simulate_state(y))
}

simulate_state(1)