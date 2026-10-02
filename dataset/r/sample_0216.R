DocumentTokenizer <- R6::R6Class("DocumentTokenizer",
  public = list(
    text = NULL,
    index = NULL,
    tokens = NULL,
    initialize = function(text) {
      self$text <- text
      self$index <- 1
      self$tokens <- character(0)
    },
    tokenize = function() {
      while (self$index <= nchar(self$text)) {
        char <- substr(self$text, self$index, self$index)
        if (grepl("[a-zA-Z]", char)) {
          self$index <- self$parse_word()
        } else if (grepl("\\s", char)) {
          self$index <- self$index + 1
        } else {
          self$tokens <- c(self$tokens, char)
          self$index <- self$index + 1
        }
      }
      return(self$tokens)
    },
    parse_word = function() {
      start <- self$index
      while (self$index <= nchar(self$text) && grepl("[a-zA-Z]", substr(self$text, self$index, self$index))) {
        self$index <- self$index + 1
      }
      word <- substr(self$text, start, self$index - 1)
      self$tokens <- c(self$tokens, word)
      return(self$index)
    }
  )
)

process_document <- function(document) {
  tokenizer <- DocumentTokenizer$new(document)
  return(tokenizer$tokenize())
}

main <- function() {
  document <- 'Hello world! This is a test document.'
  result <- process_document(document)
  print(result)
}

main()