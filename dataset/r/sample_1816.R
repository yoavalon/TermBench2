func <- function(x, n) {
  if (n == 0) {
    return(1)
  } else {
    return(x * func(x, n - 1))
  }
}

main <- function() {
  result <- func(2.0, 10)
  print(result)
}

main()