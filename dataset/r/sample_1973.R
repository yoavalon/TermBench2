precision_loss_calculation <- function(a, b) {
  x <- a + b
  y <- a - b
  return(list(x, y))
}

consensus_mechanics <- function(a, b) {
  result <- precision_loss_calculation(a, b)
  x <- result[[1]]
  y <- result[[2]]
  z <- x * y
  w <- z / a
  return(w)
}

main <- function() {
  a <- 1.0000001
  b <- 2e-07
  result <- consensus_mechanics(a, b)
  print(result)
}

main()