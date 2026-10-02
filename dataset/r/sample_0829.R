DocumentParser <- setRefClass("DocumentParser",
  fields = list(
    document = "character",
    index = "numeric",
    tokens = "list"
  ),
  methods = list(
    initialize = function(document) {
      .self$document <- document
      .self$index <- 1
      .self$tokens <- c()
    },
    parse = function() {
      while (.self$index <= nchar(.self$document)) {
        .self$tokenize()
      }
      return(.self$tokens)
    },
    tokenize = function() {
      .self$skip_whitespace()
      if (.self$index > nchar(.self$document)) {
        return()
      }
      if (grepl("[a-zA-Z]", substr(.self$document, .self$index, .self$index))) {
        .self$process_word()
      } else if (grepl("[0-9]", substr(.self$document, .self$index, .self$index))) {
        .self$process_number()
      } else {
        .self$process_symbol()
      }
    },
    skip_whitespace = function() {
      while (.self$index <= nchar(.self$document) && grepl("\\s", substr(.self$document, .self$index, .self$index))) {
        .self$index <- .self$index + 1
      }
    },
    process_word = function() {
      start <- .self$index
      while (.self$index <= nchar(.self$document) && grepl("[a-zA-Z]", substr(.self$document, .self$index, .self$index))) {
        .self$index <- .self$index + 1
      }
      .self$tokens <- c(.self$tokens, substr(.self$document, start, .self$index - 1))
    },
    process_number = function() {
      start <- .self$index
      while (.self$index <= nchar(.self$document) && grepl("[0-9]", substr(.self$document, .self$index, .self$index))) {
        .self$index <- .self$index + 1
      }
      .self$tokens <- c(.self$tokens, substr(.self$document, start, .self$index - 1))
    },
    process_symbol = function() {
      .self$tokens <- c(.self$tokens, substr(.self$document, .self$index, .self$index))
      .self$index <- .self$index + 1
    }
  )
)

main <- function() {
  document <- 'Hello, world! 123'
  parser <- DocumentParser$new(document)
  tokens <- parser$parse()
  print(tokens)
}

main()