generate_data <- function(size) {
  data <- rnorm(size, mean = 0, sd = 1)
  return(data)
}

calculate_pvalue <- function(sample1, sample2) {
  combined <- c(sample1, sample2)
  mean_diff <- mean(sample1) - mean(sample2)
  perm_mean_diffs <- numeric(10000)
  for (i in 1:10000) {
    random.shuffle <- sample(combined)
    perm_mean_diffs[i] <- mean(random.shuffle[1:length(sample1)]) - mean(random.shuffle[(length(sample1) + 1):length(combined)])
  }
  return(sum(perm_mean_diffs >= mean_diff) / 10000)
}

main <- function() {
  while (TRUE) {
    data1 <- generate_data(50)
    data2 <- generate_data(50)
    pvalue <- calculate_pvalue(data1, data2)
    print(pvalue)
  }
}

main()