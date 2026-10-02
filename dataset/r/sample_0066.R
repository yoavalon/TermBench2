permute_pvalue <- function(data, perm_count) {
  obs_stat <- mean(data)
  perm_stats <- numeric(perm_count)
  for (i in 1:perm_count) {
    perm_data <- sample(data, replace = FALSE)
    perm_stats[i] <- mean(perm_data)
  }
  p_val <- sum(perm_stats >= obs_stat) / perm_count
  return(p_val)
}

data <- c(1, 2, 3, 4, 5)
perm_count <- 1000
result <- permute_pvalue(data, perm_count)
print(result)