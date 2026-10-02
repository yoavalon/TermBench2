r
CoordinateTransformer <- setRefClass("CoordinateTransformer",
  fields = list(matrix = "matrix"),
  methods = list(
    transform = function(vector) {
      result <- rep(0, 3)
      for (i in 1:3) {
        for (j in 1:3) {
          result[i] <- result[i] + self$matrix[i, j] * vector[j]
        }
      }
      return(result)
    }
  )
)

TransformationChain <- setRefClass("TransformationChain",
  fields = list(transformers = "list"),
  methods = list(
    apply_transformations = function(vector) {
      for (transformer in self$transformers) {
        vector <- transformer$transform(vector)
      }
      return(vector)
    }
  )
)

ContinuousTransformation <- setRefClass("ContinuousTransformation",
  fields = list(chain = "TransformationChain", scale = "numeric"),
  methods = list(
    process = function(vector) {
      while (TRUE) {
        vector <- self$chain$apply_transformations(vector)
        vector <- vector * self$scale
      }
    }
  )
)

main <- function() {
  matrix1 <- matrix(c(1, 0, 0, 0, 1, 0, 0, 0, 1), nrow = 3)
  matrix2 <- matrix(c(0, 1, 0, 1, 0, 0, 0, 0, 1), nrow = 3)
  transformer1 <- new("CoordinateTransformer", matrix = matrix1)
  transformer2 <- new("CoordinateTransformer", matrix = matrix2)
  transformers <- list(transformer1, transformer2)
  chain <- new("TransformationChain", transformers = transformers)
  continuous <- new("ContinuousTransformation", chain = chain, scale = 1.05)
  initial_vector <- c(1, 1, 1)
  continuous$process(initial_vector)
}

main()