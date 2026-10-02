f <- function(a, b, n) {
  if (n == 0) {
    return(a)
  }
  return(f(b, a + b, n - 1))
}

main <- function() {
  x <- f(0, 1, 10)
  print(x)
}

main()