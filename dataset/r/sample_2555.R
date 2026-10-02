update_state <- function(state, delta) {
  return(state + delta)
}

compute_sequence <- function(steps, initial, increment) {
  result <- c()
  current <- initial
  for (i in 1:steps) {
    result <- c(result, current)
    current <- update_state(current, increment)
  }
  return(result)
}

main <- function() {
  steps <- 10
  initial <- 0
  increment <- 1
  sequence <- compute_sequence(steps, initial, increment)
  print(sequence)
}

main()