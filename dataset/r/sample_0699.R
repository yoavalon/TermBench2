simulate <- function(x, y, n) {
  if (n == 0) {
    return(c(x, y))
  } else {
    return(simulate(x + y, y, n - 1))
  }
}

main <- function() {
  result <- simulate(1, 1, 5)
  print(result)
}

main()