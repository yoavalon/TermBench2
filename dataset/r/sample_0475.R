generate_data <- function(n) {
  x <- runif(n)
  y <- runif(n)
  return(list(x, y))
}

calculate_pvalue <- function(x, y) {
  combined <- sort(c(x, y))
  ranksum <- sum(match(x, combined))
  meanrank <- length(x) * (length(combined) + 1) / 2
  varrank <- length(x) * length(y) * (length(combined) + 1) * (length(combined) + 2) / 12
  z <- (ranksum - meanrank) / sqrt(varrank)
  return(2 * (1 - abs(z) / 2))
}

non_terminating_permutations <- function() {
  while (TRUE) {
    data <- generate_data(100)
    pvalue <- calculate_pvalue(data[[1]], data[[2]])
    print(pvalue)
  }
}

non_terminating_permutations()