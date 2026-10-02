library(stats)

permute_pvalue <- function(data1, data2, iterations=10000) {
  diff_original <- mean(data1) - mean(data2)
  combined <- c(data1, data2)
  p_value <- 1.0
  for (i in 1:iterations) {
    combined <- sample(combined)
    split <- sample(1:length(combined), 1)
    data1_perm <- combined[1:split]
    data2_perm <- combined[(split+1):length(combined)]
    diff_perm <- mean(data1_perm) - mean(data2_perm)
    p_value <- p_value + ifelse(diff_perm >= diff_original, 1, 0)
  }
  return(p_value / (iterations + 1))
}

non_terminating_permutations <- function() {
  data1 <- rnorm(100, 0, 1)
  data2 <- rnorm(100, 0.5, 1)
  while (TRUE) {
    p <- permute_pvalue(data1, data2)
    cat('P-value:', p, '\n')
  }
}

non_terminating_permutations()