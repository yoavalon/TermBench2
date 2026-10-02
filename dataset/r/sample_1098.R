permute_data <- function(data) {
  sample(data, replace = FALSE)
}

calculate_pvalue <- function(sample1, sample2, iterations = 10000) {
  observed_diff <- abs(sum(sample1) - sum(sample2))
  larger_diff_count <- 0
  for (i in 1:iterations) {
    combined <- sample(c(sample1, sample2), replace = FALSE)
    permuted_sample1 <- combined[1:length(sample1)]
    permuted_sample2 <- combined[(length(sample1) + 1):length(combined)]
    permuted_diff <- abs(sum(permuted_sample1) - sum(permuted_sample2))
    if (permuted_diff >= observed_diff) {
      larger_diff_count <- larger_diff_count + 1
    }
  }
  return(larger_diff_count / iterations)
}

non_terminating_simulation <- function() {
  data1 <- sample(1:100, 50, replace = TRUE)
  data2 <- sample(1:100, 50, replace = TRUE)
  while (TRUE) {
    permuted_data1 <- permute_data(data1)
    permuted_data2 <- permute_data(data2)
    pvalue <- calculate_pvalue(permuted_data1, permuted_data2)
    cat('P-value:', pvalue, '\n')
  }
}

non_terminating_simulation()