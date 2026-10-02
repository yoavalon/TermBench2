library(dplyr)

permute <- function(data1, data2) {
  combined <- c(data1, data2)
  combined <- sample(combined)
  mid <- length(combined) %/% 2
  return(list(combined[1:mid], combined[(mid+1):length(combined)]))
}

calculate_pvalue <- function(data1, data2) {
  mean1 <- mean(data1)
  mean2 <- mean(data2)
  return(mean1 - mean2)
}

recurse <- function(data1, data2, pvalues) {
  result <- permute(data1, data2)
  group1 <- result[[1]]
  group2 <- result[[2]]
  pvalues[[length(pvalues) + 1]] <- calculate_pvalue(group1, group2)
  recurse(data1, data2, pvalues)
}

main <- function() {
  data1 <- runif(100)
  data2 <- runif(100)
  pvalues <- c()
  recurse(data1, data2, pvalues)
}

main()