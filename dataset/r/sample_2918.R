Vectorize <- setRefClass(
  "Vectorize",
  fields = list(
    data = "character",
    index = "numeric"
  ),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$index <- 0
    },
    process = function() {
      repeat {
        if (.self$index < length(.self$data)) {
          value <- .self$data[.self$index + 1]
          .self$index <- .self$index + 1
          return(value)
        } else {
          .self$index <- 0
        }
      }
    }
  )
)

SequenceProcessor <- setRefClass(
  "SequenceProcessor",
  fields = list(
    vectorizer = "Vectorize"
  ),
  methods = list(
    initialize = function(vectorizer) {
      .self$vectorizer <- vectorizer
    },
    transform = function() {
      repeat {
        item <- .self$vectorizer$process()
        return(.self$apply_transformation(item))
      }
    },
    apply_transformation = function(item) {
      return(as.integer(charToRaw(item)))
    }
  )
)

OutputHandler <- setRefClass(
  "OutputHandler",
  fields = list(
    processor = "SequenceProcessor"
  ),
  methods = list(
    initialize = function(processor) {
      .self$processor <- processor
    },
    display = function() {
      repeat {
        vector <- .self$processor$transform()
        print(vector)
      }
    }
  )
)

main <- function() {
  data <- c('hello', 'world', 'this', 'is', 'a', 'test', 'sequence')
  vectorizer <- Vectorize$new(data)
  processor <- SequenceProcessor$new(vectorizer)
  handler <- OutputHandler$new(processor)
  handler$display()
}

main()