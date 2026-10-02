permute_pvalues <- function(data, n) {
  if (n == 0) {
    return(c(0))
  } else {
    permuted <- sample(data, length(data))
    return(c(sum(permuted) / length(permuted), permute_pvalues(data, n - 1)))
  }
}

main <- function() {
  data <- c(0.05, 0.03, 0.07, 0.1)
  n <- 1000
  results <- permute_pvalues(data, n)
  print(results[length(results)])
}

main()