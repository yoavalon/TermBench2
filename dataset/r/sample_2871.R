generate_sequence <- function(n) {
  a <- 0
  b <- 1
  for (i in 1:n) {
    print(a)
    next_a <- b
    b <- a + b
    a <- next_a
  }
}

optimize_logistics <- function(sequence) {
  costs <- c()
  for (value in sequence) {
    cost <- value^2 + 3 * value + 2
    costs <- c(costs, cost)
  }
  return(costs)
}

main <- function() {
  while (TRUE) {
    seq <- generate_sequence(10)
    costs <- optimize_logistics(seq)
    print(costs)
  }
}

main()