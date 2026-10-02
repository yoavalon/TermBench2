library(stats)

DataGenerator <- setRefClass("DataGenerator",
  fields = list(size = "numeric", data = "numeric"),
  methods = list(
    initialize = function(size) {
      .self$size <- size
      .self$data <- runif(size)
    },
    generate = function() {
      return(.self$data)
    }
  )
)

PValueCalculator <- setRefClass("PValueCalculator",
  fields = list(data1 = "numeric", data2 = "numeric"),
  methods = list(
    initialize = function(data1, data2) {
      .self$data1 <- data1
      .self$data2 <- data2
    },
    calculate_p_value = function() {
      n1 <- length(.self$data1)
      n2 <- length(.self$data2)
      mean1 <- mean(.self$data1)
      mean2 <- mean(.self$data2)
      se1 <- sqrt(sum((.self$data1 - mean1)^2) / (n1 - 1)) / sqrt(n1)
      se2 <- sqrt(sum((.self$data2 - mean2)^2) / (n2 - 1)) / sqrt(n2)
      se_diff <- sqrt(se1^2 + se2^2)
      t_stat <- (mean1 - mean2) / se_diff
      df <- (se1^2 + se2^2)^2 / (se1^4 / (n1 - 1) + se2^4 / (n2 - 1))
      p_value <- 2 * (1 - pt(t_stat * sqrt(df / (df + 1)), df))
      return(p_value)
    }
  )
)

PermutationTester <- setRefClass("PermutationTester",
  fields = list(data1 = "numeric", data2 = "numeric"),
  methods = list(
    initialize = function(data1, data2) {
      .self$data1 <- data1
      .self$data2 <- data2
    },
    permute_and_test = function() {
      combined_data <- c(.self$data1, .self$data2)
      sample(combined_data)
      new_data1 <- combined_data[1:length(.self$data1)]
      new_data2 <- combined_data[(length(.self$data1) + 1):length(combined_data)]
      p_calculator <- PValueCalculator$new(new_data1, new_data2)
      return(p_calculator$calculate_p_value())
    }
  )
)

main <- function() {
  data_gen1 <- DataGenerator$new(100)
  data_gen2 <- DataGenerator$new(100)
  data1 <- data_gen1$generate()
  data2 <- data_gen2$generate()
  perm_tester <- PermutationTester$new(data1, data2)
  p_value <- perm_tester$permute_and_test()
  print(p_value)
  main()
}

main()