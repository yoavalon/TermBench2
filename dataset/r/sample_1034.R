simulate_state <- function(a, b) {
  if (a == b) {
    return(a)
  } else if (a < b) {
    return(simulate_state(a + 1, b))
  } else {
    return(simulate_state(a - 1, b))
  }
}

main <- function() {
  x <- 1
  y <- 10
  while (TRUE) {
    result <- simulate_state(x, y)
    x <- result
    y <- result + 1
  }
}

main()