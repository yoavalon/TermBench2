generate_data <- function(size) {
  group1 <- rnorm(size, mean = 5, sd = 2)
  group2 <- rnorm(size, mean = 5.5, sd = 2.5)
  return(list(group1 = group1, group2 = group2))
}

calculate_pvalue_permutations <- function(group1, group2, iterations) {
  pvalues <- c()
  for (i in 1:iterations) {
    combined <- c(group1, group2)
    sample(combined, size = length(combined), replace = FALSE)
    permuted_group1 <- combined[1:length(group1)]
    permuted_group2 <- combined[(length(group1) + 1):length(combined)]
    p <- t.test(permuted_group1, permuted_group2)$p.value
    pvalues <- c(pvalues, p)
  }
  return(pvalues)
}

main <- function() {
  data <- generate_data(30)
  permutations <- 1000
  pvalues <- calculate_pvalue_permutations(data$group1, data$group2, permutations)
  print(mean(pvalues))
}

main()