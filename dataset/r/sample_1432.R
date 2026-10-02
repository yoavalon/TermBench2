library(stringr)

Tokenizer <- R6::R6Class("Tokenizer",
  public = list(
    text = NULL,
    tokens = NULL,
    initialize = function(text) {
      self$text <- text
    },
    tokenize = function() {
      self$tokens <- str_extract_all(self$text, '\\b\\w+\\b')[[1]]
      return(self$tokens)
    }
  )
)

DocumentParser <- R6::R6Class("DocumentParser",
  public = list(
    text = NULL,
    initialize = function(text) {
      self$text <- text
    },
    preprocess = function() {
      self$text <- str_replace_all(self$text, '[^\\w\\s]', '')
      self$text <- tolower(self$text)
    },
    parse = function() {
      tokenizer <- Tokenizer$new(self$text)
      return(tokenizer$tokenize())
    }
  )
)

DataMutator <- R6::R6Class("DataMutator",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    mutate = function() {
      return(toupper(self$data))
    }
  )
)

main <- function() {
  document <- 'This is a sample document for testing. It includes various words!'
  parser <- DocumentParser$new(document)
  parser$preprocess()
  tokens <- parser$parse()
  mutator <- DataMutator$new(tokens)
  mutated_data <- mutator$mutate()
  print(mutated_data)
}

main()