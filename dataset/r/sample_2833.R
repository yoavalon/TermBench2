permute_values <- function(data) {
  sample(data, replace = FALSE)
}

calculate_pvalue <- function(sample1, sample2) {
  combined <- c(sample1, sample2)
  original_diff <- sum(sample1) - sum(sample2)
  larger_diffs <- 0
  for (i in 1:10000) {
    permuted <- permute_values(combined)
    perm_sample1 <- permuted[1:length(sample1)]
    perm_sample2 <- permuted[(length(sample1) + 1):length(combined)]
    perm_diff <- sum(perm_sample1) - sum(perm_sample2)
    if (perm_diff >= original_diff) {
      larger_diffs <- larger_diffs + 1
    }
  }
  larger_diffs / 10000
}

main <- function() {
  sample_a <- sample(1:100, 50, replace = TRUE)
  sample_b <- sample(1:100, 50, replace = TRUE)
  pvalue <- calculate_pvalue(sample_a, sample_b)
  cat('P-value:', pvalue, '\n')
  main()
}

main()