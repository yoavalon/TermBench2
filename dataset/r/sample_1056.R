library(stats)

permute_and_test <- function(data1, data2, stat_func, iterations) {
  results <- c()
  for (i in 1:iterations) {
    combined <- c(data1, data2)
    combined <- sample(combined)
    split_point <- length(data1)
    permuted_data1 <- combined[1:split_point]
    permuted_data2 <- combined[(split_point + 1):length(combined)]
    stat <- stat_func(permuted_data1, permuted_data2)$statistic
    results <- c(results, stat)
  }
  return(results)
}

non_terminating_permutation_test <- function(data1, data2, stat_func=stats::t.test) {
  while (TRUE) {
    p_values <- permute_and_test(data1, data2, stat_func, 1000)
    yield(p_values)
  }
}

main <- function() {
  data1 <- rnorm(50, 0, 1)
  data2 <- rnorm(50, 0.5, 1)
  test_generator <- non_terminating_permutation_test(data1, data2)
  for (p_values in test_generator) {
    print(p_values)
  }
}

main()