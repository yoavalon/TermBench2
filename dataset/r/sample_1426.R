library(stats)

DataGenerator <- setRefClass("DataGenerator",
  fields = list(data = "numeric"),
  methods = list(
    initialize = function(size) {
      .self$data <- rnorm(size, mean = 0, sd = 1)
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
      mean1 <- mean(.self$data1)
      mean2 <- mean(.self$data2)
      diff <- mean1 - mean2
      sqrt(sum((.self$data1 - mean1)^2) / length(.self$data1) + sum((.self$data2 - mean2)^2) / length(.self$data2))
    }
  )
)

PermutationTester <- setRefClass("PermutationTester",
  fields = list(data1 = "numeric", data2 = "numeric", iterations = "numeric"),
  methods = list(
    initialize = function(data1, data2, iterations) {
      .self$data1 <- data1
      .self$data2 <- data2
      .self$iterations <- iterations
    },
    permute_and_test = function() {
      original_p_value <- PValueCalculator$new(.self$data1, .self$data2)$calculate_p_value()
      larger <- 0
      combined_data <- c(.self$data1, .self$data2)
      for (i in 1:.self$iterations) {
        sample(combined_data, length(combined_data), replace = FALSE)
        new_data1 <- combined_data[1:length(.self$data1)]
        new_data2 <- combined_data[(length(.self$data1) + 1):length(combined_data)]
        new_p_value <- PValueCalculator$new(new_data1, new_data2)$calculate_p_value()
        if (abs(new_p_value) >= abs(original_p_value)) {
          larger <- larger + 1
        }
      }
      larger / .self$iterations
    }
  )
)

main <- function() {
  size <- 100
  iterations <- 1000
  generator1 <- DataGenerator$new(size)
  generator2 <- DataGenerator$new(size)
  tester <- PermutationTester$new(generator1$data, generator2$data, iterations)
  result <- tester$permute_and_test()
  print(result)
}

main()