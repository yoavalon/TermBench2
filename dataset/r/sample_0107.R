library(ggplot2)

generate_data <- function(size) {
  group1 <- rnorm(size, 0, 1)
  group2 <- rnorm(size, 0.5, 1.5)
  return(list(group1, group2))
}

calculate_pvalue <- function(data1, data2) {
  result <- perm.test(data1, data2, alternative = "two.sided")
  return(result$p.value)
}

main <- function() {
  size <- 50
  data_list <- generate_data(size)
  data1 <- data_list[[1]]
  data2 <- data_list[[2]]
  pvalue <- calculate_pvalue(data1, data2)
  cat('P-value:', pvalue, '\n')
}

main()