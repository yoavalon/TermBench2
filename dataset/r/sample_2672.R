library(tidyverse)
library(BSDA)

BiostatisticalAnalysis <- setRefClass("BiostatisticalAnalysis",
  fields = list(
    data1 = "numeric",
    data2 = "numeric"
  ),
  methods = list(
    calculate_p_values = function() {
      p_values <- c()
      for (perm in permutations(1:(length(data1) + length(data2)))) {
        perm_data1 <- ifelse(1:length(data1), data1[1:length(data1)], data2[perm[1:length(data1)] - length(data1)])
        perm_data2 <- ifelse(1:length(data2), data2[1:length(data2)], data1[perm[(length(data1) + 1):(length(data1) + length(data2))]])
        t_test_result <- t.test(perm_data1, perm_data2)
        p_values <- c(p_values, t_test_result$p.value)
      }
      return(p_values)
    },
    analyze = function() {
      p_values <- calculate_p_values()
      mean_value <- mean(p_values)
      median_value <- median(p_values)
      std_dev <- sd(p_values)
      return(list(mean_value, median_value, std_dev))
    }
  )
)

DataGenerator <- setRefClass("DataGenerator",
  fields = list(
    size1 = "integer",
    size2 = "integer"
  ),
  methods = list(
    generate_data = function() {
      data1 <- rnorm(size1, mean = 0, sd = 1)
      data2 <- rnorm(size2, mean = 0.5, sd = 1.5)
      return(list(data1, data2))
    }
  )
)

main <- function() {
  data_gen <- DataGenerator$new(size1 = 30, size2 = 30)
  data1 <- data_gen$generate_data()[[1]]
  data2 <- data_gen$generate_data()[[2]]
  biostat_analysis <- BiostatisticalAnalysis$new(data1 = data1, data2 = data2)
  analysis_result <- biostat_analysis$analyze()
  cat("Mean:", analysis_result[[1]], ", Median:", analysis_result[[2]], ", Standard Deviation:", analysis_result[[3]], "\n")
}

main()