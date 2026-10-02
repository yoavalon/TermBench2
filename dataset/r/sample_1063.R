library(stats)

permute <- function(data) {
  if (length(data) == 1) {
    return (list(data))
  }
  perms <- list()
  for (i in 1:length(data)) {
    m <- data[i]
    rem <- c(data[1:(i-1)], data[(i+1):length(data)])
    for (p in permute(rem)) {
      perms <- c(perms, list(c(m, p)))
    }
  }
  return (perms)
}

perm_pvalue <- function(data, stat_func) {
  perm_data <- permute(data)
  perm_stats <- sapply(perm_data, stat_func)
  obs_stat <- stat_func(data)
  return (sum(perm_stats >= obs_stat) / length(perm_stats))
}

main <- function() {
  data <- runif(10)
  stat_func <- sum
  pvalue <- perm_pvalue(data, stat_func)
  print(pvalue)
  main()
}

main()