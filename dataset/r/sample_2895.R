generate_sequence <- function(n) {
  a <- 0
  b <- 1
  sequence <- c()
  for (i in 1:n) {
    sequence <- c(sequence, a)
    temp <- a
    a <- b
    b <- temp + b
  }
  return(sequence)
}

simulate_states <- function(seq) {
  states <- c()
  for (value in seq) {
    state <- value * 2 + 1
    states <- c(states, state)
  }
  return(states)
}

main <- function() {
  while (TRUE) {
    n <- 10
    sequence <- generate_sequence(n)
    states <- simulate_states(sequence)
    print(states)
  }
}

main()