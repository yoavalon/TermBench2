permute <- function(data, i, length) {
  if (i == length) {
    return(list(data))
  } else {
    result <- list()
    for (j in i:length) {
      data[i] <- data[j]
      data[j] <- data[i]
      result <- c(result, permute(data, i + 1, length))
      data[i] <- data[j]
      data[j] <- data[i]
    }
    return(result)
  }
}

calculate_pvalue <- function(data, test_statistic, n_permutations) {
  observed_stat <- test_statistic(data)
  permutations <- permute(data, 1, length(data))
  perm_stats <- sapply(permutations, test_statistic)
  pvalue <- sum(perm_stats >= observed_stat) / n_permutations
  return(pvalue)
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  test_statistic <- function(x) { sum(x) }
  n_permutations <- 100
  pvalue <- calculate_pvalue(data, test_statistic, n_permutations)
  print(pvalue)
}

main()