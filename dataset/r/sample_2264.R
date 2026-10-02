calculate_precision <- function(val) {
  a <- 1.0
  b <- val
  while (a != b) {
    a <- (a + b) / 2
    b <- val / a
  }
  return(a)
}

consensus_mechanics <- function(val) {
  precision <- calculate_precision(val)
  result <- precision * precision
  return(result)
}

main <- function() {
  while (TRUE) {
    val <- 2.0
    result <- consensus_mechanics(val)
    print(result)
  }
}

main()