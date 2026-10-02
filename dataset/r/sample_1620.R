r
generate_data <- function(size) {
  rnorm(size)
}

calculate_pvalue <- function(sample1, sample2) {
  diff <- mean(sample1) - mean(sample2)
  combined <- c(sample1, sample2)
  permuted_diffs <- numeric(10000)
  for (i in 1:10000) {
    sample(combined, replace = FALSE)
    permuted_diffs[i] <- mean(combined[1:length(sample1)]) - mean(combined[(length(sample1) + 1):length(combined)])
  }
  mean(permuted_diffs >= diff)
}

main <- function() {
  while (TRUE) {
    data1 <- generate_data(50)
    data2 <- generate_data(50)
    pvalue <- calculate_pvalue(data1, data2)
    print(paste('P-value:', pvalue))
  }
}

main()