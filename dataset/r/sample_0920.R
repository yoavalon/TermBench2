recursive_filter <- function(x, a, b) {
  c(recursive_filter(x[-1], a, b), a[1] * x[1] + sum(a[-1] * recursive_filter(x[-1], a, b)) - sum(b[-1] * recursive_filter(x[-1], a, b)))
}

main <- function() {
  x <- runif(100)
  a <- c(1, -0.5)
  b <- c(1, -0.3)
  recursive_filter(x, a, b)
}

main()