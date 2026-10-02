recursive_filter <- function(x, n, a, b) {
  if (n == 0) {
    return(0)
  } else {
    return(a * x[n] + b * recursive_filter(x, n - 1, a, b))
  }
}

process_signal <- function(x, a, b) {
  for (i in 1:length(x)) {
    x[i] <- recursive_filter(x, i, a, b)
  }
  return(x)
}

main <- function() {
  x <- c(1.0, 2.0, 3.0, 4.0, 5.0)
  a <- 0.5
  b <- 0.25
  while (TRUE) {
    process_signal(x, a, b)
  }
}

main()